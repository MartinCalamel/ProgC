/* main_liste.c
* Auteur : Martin
*/

#include <stdio.h>
#include "liste.h"

int main(){
	// teste la structure de donnée de liste simplement chainée
	struct color premier;
	premier.next= NULL;
	premier.rouge = 'a';
	premier.vert = 'b';
	premier.bleu = 'c';

	struct color c1;
	c1.rouge = 'd';
	c1.vert = 'e';
	c1.bleu = 'f';

	insertion(&premier, &c1);

	parcours(&premier);

}
