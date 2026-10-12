#include <stdio.h>

int main() {
    int A, B, C;

    printf("Digite o valor de A: ");
    scanf("%d", &A);

    printf("Digite o valor de B: ");
    scanf("%d", &B);

    printf("Digite o valor de C: ");
    scanf("%d", &C);

    if (A + B < C) {
        printf("A soma de A + B (%d) e MENOR que C (%d).\n", A + B, C);
    } 
    
    else {
        printf("A soma de A + B (%d) NAO e menor que C (%d).\n", A + B, C);
    }

    return 0;
}