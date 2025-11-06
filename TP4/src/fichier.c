/* fichier.c
* Auteur : Armand
*/

#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

void lire_fichier (char * nom){
	FILE *f=fopen(nom,"r");
	fseek(f, 0, SEEK_END);
	long taille = ftell(f);
	rewind(f);
	
	// utilisation de la taille du fichier pour definir le buffer 
	char *buffer = malloc(taille + 1);

	// lecture du fichier avec fread
	size_t lus = fread(buffer, 1, taille, f);
	buffer[lus] = '\0';

	printf("Contenu du fichier :\n%s\n", buffer);

	free(buffer);
	fclose(f);
}

void ecrire_dans_fichier(char*nom, char*texte ){
	 // érciture dans le fichier avec fprintf
	 FILE *fichier = fopen(nom, "w");
	 fprintf(fichier, "%s", texte);
	 fclose(fichier);

}
