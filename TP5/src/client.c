/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"

int get_note(char *file_name){
	int note = 0;
	FILE *fd = fopen(file_name, "r");
	fscanf(fd, "%d", &note);
	fclose(fd);
	return note;
}

int envoie_notes(int socketfd){
	int etud;
	
	printf("Etudiant dont vous voulez calculer la moyenne [1-5] :\n> ");
	scanf("%d", &etud);
	int somme = 0;
	for (int i = 1; i<6; i++){
		char path [1000] = "../etudiant/";
		char data[1000];
		sprintf(path, "%s%i/note%i.txt", path, etud, i);
		
		int note = get_note(path);
		char message[1000];
		sprintf(message, "calcule : + %i %i\n", somme, note);
		// Envoie le message au client
		int write_status = write(socketfd, message, strlen(message));
		if (write_status < 0)
		{
			perror("Erreur d'écriture");
			return -1;
		}
		// Réinitialisation de l'ensemble des données
		memset(data, 0, sizeof(data));

		// Lit les données de la socket
		int read_status = read(socketfd, data, sizeof(data));
		if (read_status < 0)
		{
			perror("Erreur de lecture");
			return -1;
		}
		sscanf(data, "%i", &somme);
	}
	char message[1000];
	char data[1000];	
	sprintf(message, "calcule : / %i 5", somme);
	int write_status = write(socketfd, message, strlen(message));
	if (write_status < 0)
        {
        	perror("Erreur d'écriture");
                return -1;
        }
        // Réinitialisation de l'ensemble des données
        memset(data, 0, sizeof(data));

        // Lit les données de la socket
        int read_status = read(socketfd, data, sizeof(data));
        if (read_status < 0)
        {
        	perror("Erreur de lecture");
                return -1;
        }
        sscanf(data, "%i", &somme);
	printf("moyenne de l'etudiant %i : %i\n", etud, somme); 
}


int envoie_operateur_numeros(int socketfd){
	char message[1000];
	char data[1000];

	printf("entrez votre calcule : \n>>> ");
	fgets(message, 1000, stdin);
	
	strcpy(data, "calcule : ");
	strcat(data, message);
	
	// Envoie le message au client
  	int write_status = write(socketfd, data, strlen(data));
  	if (write_status < 0)
  	{
    		perror("Erreur d'écriture");
		return -1;
	}

	// Réinitialisation de l'ensemble des données
	memset(data, 0, sizeof(data));

	// Lit les données de la socket
	int read_status = read(socketfd, data, sizeof(data));
	if (read_status < 0)
	{
		perror("Erreur de lecture");
	   	return -1;
	}

	// Affiche le message reçu du client
	printf("Calcule : %s\n", data);

	return 0; // Succès
}


/**
 * Fonction pour envoyer et recevoir un message depuis un client connecté à la socket.
 *
 * @param socketfd Le descripteur de la socket utilisée pour la communication.
 * @return 0 en cas de succès, -1 en cas d'erreur.
 */
int envoie_recois_message(int socketfd)
{
  char data[1024];

  // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Demande à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre message (max 1000 caractères): ");
  fgets(message, sizeof(message), stdin);

  // Construit le message avec une étiquette "message: "
  strcpy(data, "message: ");
  strcat(data, message);

  // Envoie le message au client
  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("Erreur d'écriture");
    return -1;
  }

  // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Lit les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("Erreur de lecture");
    return -1;
  }

  // Affiche le message reçu du client
  printf("Message reçu: %s\n", data);

  return 0; // Succès
}

int main()
{
  int socketfd;

  struct sockaddr_in server_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0)
  {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    // faire le choix (calcule ou message)
    short choix;
    printf("faire un choix : \n  [0] envoyer un message\n  [1] envoyer un calcule\n  [2] envoyer des notes\n> ");
    scanf("%hd", &choix);
    while(getchar() != '\n');
    if (!choix){ 
      // appeler la fonction pour envoyer un message au serveur
      envoie_recois_message(socketfd);
    } else if (!(choix - 1)){
      envoie_operateur_numeros(socketfd);
    } else {
      envoie_notes(socketfd);
    }
  }

  close(socketfd);
}
