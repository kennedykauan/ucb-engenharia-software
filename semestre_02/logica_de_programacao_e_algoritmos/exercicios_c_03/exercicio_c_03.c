#include <stdio.h>

int main() {
    float A[10], B[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &A[i]);
        B[i] = A[i] * A[i];
    }

    printf("\nVetor A (originais):\n");
    for (i = 0; i < 10; i++) {
        printf("%.2f\n", A[i]);
    }

    printf("\nVetor B (quadrados):\n");
    for (i = 0; i < 10; i++) {
        printf("%.2f\n", B[i]);
    }

    return 0;
}