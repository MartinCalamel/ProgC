/* etudient_bd.c
* Auteur : Armand
*/

#include <stdio.h>
#include <string.h>
#include "fichier.h"

int main(){
	// definition de la structure
	struct etudiant{
		char nom[30];
		char prenom[30];
		char address[100];
		char note[2][10];
        };
	int TAILLE = 5;
	struct etudiant tab[TAILLE];
	memset(tab, 0,TAILLE * sizeof(struct etudiant));

	// user interface
	for(int i=0; i<TAILLE; i++){
		char temps[100];
		
		printf("Nom : ");
		fgets(temps, 30, stdin);
		strncpy(tab[i].nom, temps, strlen(temps)-1);
		
		printf("Prénom : ");
		fgets(temps, 30, stdin);
		strncpy(tab[i].prenom, temps, strlen(temps)-1);

		printf("adresse : ");
		fgets(temps, 100, stdin);
		strncpy(tab[i].address, temps, strlen(temps)-1);

		printf("Note 1 : ");
		fgets(temps, 10, stdin);
		strncpy(tab[i].note[0], temps, strlen(temps)-1);
		
		printf("Note 2 : ");
		fgets(temps, 10, stdin);
		strncpy(tab[i].note[1], temps, strlen(temps)-1);
	}	

	// formatage de la donné
 	char message[5][180];
	for(int i=0; i<TAILLE; i++){
		message[i][0]='\0';
		strcat(message[i], tab[i].nom);
		strcat(message[i], ";");
		strcat(message[i], tab[i].prenom);
		strcat(message[i], ";");
		strcat(message[i], tab[i].address);
		strcat(message[i], ";");
		strcat(message[i], tab[i].note[0]);
		strcat(message[i], ";");
		strcat(message[i], tab[i].note[1]);
		strcat(message[i], "\n");
		printf("%s\n", message[i]);
	}
	char message_fin[900]={'\0'};
	for(int i=0; i<5; i++){
		strcat(message_fin, message[i]);
	}
	ecrire_dans_fichier("etudiants.txt", message_fin);

	return 0;
}
