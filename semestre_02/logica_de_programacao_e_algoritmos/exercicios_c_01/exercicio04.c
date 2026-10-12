#include<stdio.h>

int main()
{
    float salario, novo_salario;

    printf("Digite o valor do salario do funcionario: ");
    scanf("%f", &salario);

    novo_salario = salario * 1.25;

    printf("O novo salario do funcionario eh: %.2f\n", novo_salario);
    
    return 0;
}