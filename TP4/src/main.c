#include "fichier.h"
#include <stdio.h>

int main(){
	char nom_de_fichier[100];
	printf("Nom du fichier : ");
	scanf("%s", nom_de_fichier);
	while(getchar() != '\n');
	
	int choix;
	
	printf("Que souhaitez-vous faire ?\n1. Lire un fichier\n2. Ecrire dans un fichier\nVotre choix : ");

	scanf("%i", &choix);
	while(getchar()!= '\n');

	if (choix-1){
		char message[1000];
		printf("Votre message :\n");
		fgets(message, 1000, stdin);
		ecrire_dans_fichier(nom_de_fichier, message);
	}
	else{
		lire_fichier(nom_de_fichier);

	}
}
