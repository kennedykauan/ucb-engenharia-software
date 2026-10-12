#include <stdio.h>

int main() {
    int A, B, C;

    printf("Digite o valor de A: ");
    scanf("%d", &A);

    printf("Digite o valor de B: ");
    scanf("%d", &B);

    if (A == B) {
        C = A + B;
    } 
    
    else {
        C = A * B;
    }

    printf("O resultado armazenado em C e: %d\n", C);

    return 0;
}