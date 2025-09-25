#include <stdio.h>

int main() {
    int N;
    int i = 1;
    int som = 0;
    printf("Entrez un entier positif N: ");
    scanf("%d", &N);
    if (N <= 0) {
        printf("Erreur: veuillez entrer un entier positif.\n");
        return 1;
    }
    while (i <= N) {
        som = som + i;
        i = i + 1;  
    }
    printf("La somme des entiers de 1 a %d est: %d\n", N, som);
    return 0;
}
