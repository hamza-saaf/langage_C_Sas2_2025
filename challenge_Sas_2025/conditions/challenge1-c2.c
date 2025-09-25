#include <stdio.h>

int main() {
    float ra, dp;
    int sc;

    printf("Donner revenu annuel (en euros): ");
    scanf("%f", &ra);

    printf("Donner Score de credit (sur 1000): ");
    scanf("%d", &sc);

    printf("Donner Duree du pret (en annees): ");
    scanf("%f", &dp);

    if (ra >= 30000 && sc >= 700 && dp <= 10) {
        printf("Eligible\n");
    }
    else if (ra >= 30000 && sc >= 650 && dp <= 15) {
        printf("Eligible avec conditions\n");
    }
    else {
        printf("Non Eligible\n");
    }

    return 0;
}
