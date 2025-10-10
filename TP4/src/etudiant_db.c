#include <stdio.h>
#include <string.h>
//#include <fichier.h>

int main(){
	struct etudiant{
		char nom[30];
		char prenom[30];
		char address[100];
		float note[2];
        };
	int TAILLE = 5;
	struct etudiant tab[TAILLE];
	
	for(int i; i<TAILLE; i++){
		char temps[100];
		float tempf;
		
		printf("Nom : ");
		fgets(temps, 100, stdin);
		strcpy(tab[i].nom, temps);
		
		printf("Prénom : ");
		fgets(temps, 100, stdin);
		strcpy(tab[i].prenom, temps);

		printf("adresse : ");
		fgets(temps, 100, stdin);
		strcpy(tab[i].address, temps);

		printf("Note 1 : ");
		scanf("%f", &tempf);
		while(getchar() != '\n');
		tab[i].note[1] = tempf;
		
		printf("Note 2 : ");
		scanf("%f", &tempf);
		while(getchar() != '\n');
		tab[i].note[2] = tempf;
	}	
	

	return 0;
}
