#include <stdio.h>

int main() {
    int vetor[10];
    int i, maior, posicao;

    for (i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    posicao = 0;

    for (i = 1; i < 10; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            posicao = i;
        }
    }

    printf("\nVetor:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n\nMaior elemento: %d\n", maior);
    printf("Posicao: %d\n", posicao);

    return 0;
}