/* repertoire.c
* Auteur : Armand
*/

#include "repertoire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void lire_dossier_recursif(const char *nom_repertoire) {
    DIR *dirp = opendir(nom_repertoire);
    if (dirp == NULL) {
        perror(nom_repertoire);
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(dirp)) != NULL) { // tant que le dossier n'est pas vide
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) // on exclut lui même et ses parents
            continue;

        char chemin[1024];
        snprintf(chemin, sizeof(chemin), "%s/%s", nom_repertoire, ent->d_name);

        printf("%s\n", chemin);

        struct stat st;
        if (stat(chemin, &st) == 0 && S_ISDIR(st.st_mode)) {
            lire_dossier_recursif(chemin);
        }
    }

    closedir(dirp);
}


void lire_dossier_iteratif(const char *nom_repertoire) {
    char **pile = NULL;
    int taille_pile = 0;

    pile = realloc(pile, sizeof(char *));
    pile[0] = strdup(nom_repertoire);
    taille_pile = 1;

    while (taille_pile > 0) {
        char *repertoire_courant = pile[taille_pile - 1];
        taille_pile--;

        DIR *dirp = opendir(repertoire_courant);
        if (dirp == NULL) {
            perror(repertoire_courant);
            free(repertoire_courant);
            continue;
        }

        struct dirent *ent;
        while ((ent = readdir(dirp)) != NULL) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
                continue;

            char chemin[1024];
            snprintf(chemin, sizeof(chemin), "%s/%s", repertoire_courant, ent->d_name);

            printf("%s\n", chemin);

            struct stat st;
            if (stat(chemin, &st) == 0 && S_ISDIR(st.st_mode)) {
                pile = realloc(pile, sizeof(char *) * (taille_pile + 1));
                pile[taille_pile] = strdup(chemin);
                taille_pile++;
            }
        }

        closedir(dirp);
        free(repertoire_courant); // Libère le dossier dépilé
    }

    free(pile);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s <nom_du_repertoire>\n", argv[0]);
        return 1;
    }

    lire_dossier_iteratif(argv[1]);
    return 0;
}
