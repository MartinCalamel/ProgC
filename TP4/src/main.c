/* main.c
* Auteur : Armand
*/
#include <stdio.h>
#include "operator.h"
#include "fichier.h"
#include <stdlib.h>
#include <string.h>

int main (){
	printf("pour lire un fichier tapez 1, pour écrire dans un fichier tapez 2 , pour faire de opérations tapez 3 \n ");
	int choix ;
	scanf("%i",&choix);
	while(getchar() != '\n');
	char nom_de_fichier[100];
	
	if ( choix == 1 ){
		// pour écrire dans un fichier 
		printf( "entrez le nom de fichier : \n");
		scanf("%s",nom_de_fichier);
		while(getchar() != '\n');
		lire_fichier(nom_de_fichier);
		
	} else if ( choix == 2 ){
		// pour lire dans un fichier
		printf( "entrez le nom de fichier : \n");
                scanf("%s",nom_de_fichier);
                while(getchar() != '\n');
		char texte[100];
		printf("Entrez le texte à écrire :\n");
	        if (fgets(texte, sizeof(texte), stdin) != NULL) { 
	    	size_t len = strlen(texte);
		        if (len > 0 && texte[len - 1] == '\n') {
		            texte[len - 1] = '\0';
        		}
    		}
                ecrire_dans_fichier(nom_de_fichier,texte);
		
	} else if (choix == 3 ){
		// pour faire des opération
		printf("tapez l'entier a: \n");
		int a;
		scanf("%i",&a);
		while(getchar() != '\n');
		printf("tapez l'entier b: \n");
	        int b;
	        scanf("%i",&b);
		while(getchar() != '\n');
		printf("saisissez l'opérateur voulu \n");
		char op;
		scanf("%c",&op);
		printf("\n a=%i, b= %i, op=%c \n",a,b,op);
		while(getchar() != '\n');
		switch(op){
			case '+':
				printf("%i \n",somme(a,b));
				break;
			case '-':
				printf("%i \n", différence(a,b));
                	        break;
			case '*':
				printf("%i \n",produit(a,b));
                	        break;
			case '/':
				printf("%i \n",quotient(a,b));
                	        break;
			case '%':
				printf("%i \n",modulo(a,b));
                	        break;
			case '&':
				printf("%i \n",et(a,b));
        	                break;
			case '|':
				printf("%i \n",ou(a,b));
	                        break;
			case '~':
				printf("%i \n", négation(a));
	                        break;
			default:
				printf("Opérateur pas reconnue \n");

		}
	}
	return 0;
}
