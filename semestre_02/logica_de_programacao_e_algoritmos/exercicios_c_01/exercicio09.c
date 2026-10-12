#include<stdio.h>

int main(){
    float area, base, altura;

    printf("Digite a base do triangulo: ");
    scanf("%f", &base);

    printf("Digite a altura do triangulo: ");
    scanf("%f", &altura);

    area = (base * altura) / 2;

    printf("A area do triangulo eh: %.2f\n", area);

    return 0;

}