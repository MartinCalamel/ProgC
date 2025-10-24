#include <stdio.h>
#include "operator.h"
#include <stdlib.h>

int main (int argc, char *argv[]){
	if (argc < 2) {
		printf("Usage: readdir path\n");
		return(EXIT_FAILURE);
	};
	char op =argv[2][0];
	int a = atoi(argv[1]);
	int b = atoi(argv[3]);
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

