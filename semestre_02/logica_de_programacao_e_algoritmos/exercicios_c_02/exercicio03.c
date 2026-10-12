#include <stdio.h>

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("O numero %d e PAR.\n", numero);
    }

    else {
        printf("O numero %d e IMPAR.\n", numero);
    }

    return 0;
}