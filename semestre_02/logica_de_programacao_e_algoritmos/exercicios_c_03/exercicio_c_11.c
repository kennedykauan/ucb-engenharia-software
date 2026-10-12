#include <stdio.h>

int main() {
    float vetor[10];
    float somaPositivos = 0;
    int negativos = 0;
    int i;

    for (i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &vetor[i]);

        if (vetor[i] < 0) {
            negativos++;
        } else if (vetor[i] > 0) {
            somaPositivos += vetor[i];
        }
    }

    printf("\nQuantidade de numeros negativos: %d\n", negativos);
    printf("Soma dos numeros positivos: %.2f\n", somaPositivos);

    return 0;
}