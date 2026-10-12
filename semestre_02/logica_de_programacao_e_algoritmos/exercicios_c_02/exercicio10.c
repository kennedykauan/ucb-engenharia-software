#include <stdio.h>

int main() {
    float peso, altura, imc;

    printf("Digite o peso em kg: ");
    scanf("%f", &peso);

    printf("Digite a altura em metros: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("\nSeu IMC e: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } 
    
    else if (imc >= 18.5 && imc < 25.0) {
        printf("Peso normal\n");
    } 
    
    else if (imc >= 25.0 && imc <= 30.0) {
        printf("Acima do peso\n");
    } 
    
    else {
        printf("Obeso\n");
    }

    return 0;
}