#include <stdio.h>
#include <stdbool.h>

int main() {
    int valor1_int, valor2_int;
    bool A, B;

    printf("Digite o primeiro valor logico (1 para VERDADEIRO, 0 para FALSO): ");
    scanf("%d", &valor1_int);
    A = (valor1_int != 0);

    printf("Digite o segundo valor logico (1 para VERDADEIRO, 0 para FALSO): ");
    scanf("%d", &valor2_int);
    B = (valor2_int != 0);

    if (A && B) {
        printf("Ambos os valores sao VERDADEIROS.\n");
    } 
    
    else if (!A && !B) {
        printf("Ambos os valores sao FALSOS.\n");
    } 
    
    else {
        printf("Os valores sao DIFERENTES (um e verdadeiro e o outro e falso).\n");
    }

    return 0;
}