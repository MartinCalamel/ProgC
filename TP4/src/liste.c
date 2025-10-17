#include <stdio.h>
#include "liste.h"

void insertion(struct color *premier, struct color *couleur){
	struct color* next = premier->next;
	couleur->next = next;
	premier->next = couleur;
}


void parcours(struct color *premier){
	struct color *elem = premier;
	int i = 0;
	while(elem != NULL){
		printf("couleur %i :\n    rouge : %c\n    vert : %c\n    bleu : %c\n\n",i, elem->rouge, elem->vert, elem->bleu);
		elem = elem->next;
		i++;
	}
	
}
