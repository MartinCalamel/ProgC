#include <stdio.h>

// Définition de la fonction factorielle
int factorielle(int num) {
  if (num == 0) {
    printf("fact(0): 1\n");
    return 1;
  } else {
    int valeur = num * factorielle(num - 1);
    printf("fact(%d): %d\n", num, valeur);
    return (valeur);
  }
}

int main() {
  int n;
  
  // Testez la fonction factorielle avec différentes valeurs d'entiers naturels
  printf("%i\n", factorielle(1));
  printf("%i\n", factorielle(5));
  return 0;
}
