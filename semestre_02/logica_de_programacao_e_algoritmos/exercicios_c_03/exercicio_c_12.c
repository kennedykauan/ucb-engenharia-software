#include <stdio.h>

int main() {
    float valores[5];
    float maior, menor, soma = 0, media;
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &valores[i]);
        soma += valores[i];
    }

    maior = valores[0];
    menor = valores[0];

    for (i = 1; i < 5; i++) {
        if (valores[i] > maior) {
            maior = valores[i];
        }
        if (valores[i] < menor) {
            menor = valores[i];
        }
    }

    media = soma / 5;

    printf("\nValores lidos:\n");
    for (i = 0; i < 5; i++) {
        printf("%.2f\n", valores[i]);
    }

    printf("\nMaior: %.2f\n", maior);
    printf("Menor: %.2f\n", menor);
    printf("Media: %.2f\n", media);

    return 0;
}