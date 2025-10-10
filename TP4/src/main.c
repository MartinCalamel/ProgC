#include <stdio.h>
#include "operator.h"
#include "fichier.h"
#include <stdlib.h>

int main (){
	lire_fichier("new.txt");
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
	while(getchar() != '\n');
	printf("\n a=%i, b= %i, op=%c \n",a,b,op);
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
	return 0;
}
