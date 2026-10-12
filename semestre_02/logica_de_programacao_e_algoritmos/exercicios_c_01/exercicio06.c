#include<stdio.h>

int main(){
    float salario_base, novo_salario;

    printf("Digite o salario base: ");
    scanf("%f", &salario_base);

    novo_salario = salario_base + (salario_base * 0.05) - (salario_base * 0.07);

    printf("O salario atualizado do funcionario com a gratificação e desconto do imposto eh: %.2fR$\n", novo_salario);



    return 0;
}