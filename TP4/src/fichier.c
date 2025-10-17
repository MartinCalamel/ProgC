#include <stdio.h>
#include "fichier.h"
void lire_fichier(char * nom_de_fichier){
	printf("Lecture du fichier %s\n", nom_de_fichier);
	char temp[10000];
	FILE *fp = fopen(nom_de_fichier, "r");
	fread(temp, 10000, 1000, fp);
	fclose(fp);
	printf("%s", temp);
	printf("Lecture OK\n");
}

void ecrire_dans_fichier(char * nom_de_fichier, char * message){
	int taille=0;
	while(message[taille]!='\0'){taille++;}
	printf("Ecriture dans le fichier : %s\n", nom_de_fichier);
	FILE *fp = fopen(nom_de_fichier, "w");
	fwrite(message, taille, 1, fp);
	printf("Ecriture OK\n");
	fclose(fp);	
}
