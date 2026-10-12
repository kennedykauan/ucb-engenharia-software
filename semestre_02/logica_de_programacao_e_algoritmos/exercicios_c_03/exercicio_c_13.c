#include <stdio.h>

int main() {
    float valores[5];
    float maior, menor;
    int posMaior, posMenor, i;

    for (i = 0; i < 5; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &valores[i]);
    }

    maior = valores[0];
    menor = valores[0];
    posMaior = 0;
    posMenor = 0;

    for (i = 1; i < 5; i++) {
        if (valores[i] > maior) {
            maior = valores[i];
            posMaior = i;
        }
        if (valores[i] < menor) {
            menor = valores[i];
            posMenor = i;
        }
    }

    printf("\nMaior valor: %.2f (posicao %d)\n", maior, posMaior);
    printf("Menor valor: %.2f (posicao %d)\n", menor, posMenor);

    return 0;
}