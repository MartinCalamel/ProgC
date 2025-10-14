#include <stdio.h>
#include <string.h>

int in_line(char * line, char * phrase){
	int j = 0;
	int result = 0;
	for(long unsigned int i = 0; i < strlen(line); i++){
		if ((* (line + i)) == (* (phrase + j))){
			if ((* (phrase + j)) == '\n'){
				result++;
				j = 0;
			} else {
				j++;
			}
		}
		else {
			if (((* (phrase + j)) == '\n') || ((* (phrase + j)) == '\0')){
				result++;
			}
			j = 0;	
		}
	}
	return result;
}


int main(int argc, char **argv){
	if (argc < 2){
		printf("Pas de fichier passé en paramètre\n");
		return(1);
	}
	char * fichier = argv[1];
	printf("Fichier Cible : %s\n", fichier);
	
	printf("Phrase à chercher : ");
	char phrase[1000];
	fgets(phrase, 1000, stdin);
	


	FILE *fp = fopen(fichier, "r");

	char line[1000];
	int line_compteur = 0;
	int result;

	printf("\n\nResults : \n");
	
	while (fgets(line, 1000, fp) != NULL){
		result = in_line(line, phrase);
		if (result > 0){
			printf("line %i : %i found\n", line_compteur, result);
		}
		line_compteur++;
	} 

	return 0;
}
