#include <stdio.h>

int main() {
    int vetor[8];
    int x, y, soma, i;

    for (i = 0; i < 8; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("Digite a posicao X: ");
    scanf("%d", &x);
    printf("Digite a posicao Y: ");
    scanf("%d", &y);

    if (x < 0 || x > 7 || y < 0 || y > 7) {
        printf("Posicao invalida! Use valores de 0 a 7.\n");
        return 1;
    }

    soma = vetor[x] + vetor[y];
    printf("Soma de vetor[%d] + vetor[%d] = %d\n", x, y, soma);

    return 0;
}