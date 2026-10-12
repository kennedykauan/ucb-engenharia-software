#include <stdio.h>

int main() {
    int numero, resultado;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        resultado = numero + 5;
    } 
    
    else {
        resultado = numero + 8;
    }

    printf("O resultado da operacao e: %d\n", resultado);

    return 0;
}