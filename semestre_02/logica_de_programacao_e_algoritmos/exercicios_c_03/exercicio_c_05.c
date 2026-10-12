#include <stdio.h>

int main() {
    int vetor[10];
    int i, pares = 0;

    for (i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
        if (vetor[i] % 2 == 0) {
            pares++;
        }
    }

    printf("Quantidade de valores pares: %d\n", pares);

    return 0;
}