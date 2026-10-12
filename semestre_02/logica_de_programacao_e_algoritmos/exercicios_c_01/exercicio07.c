#include<stdio.h>

int main(){
    float salario_base, novo_salario;

    printf("Digite o salario base: ");
    scanf("%f", &salario_base);

    novo_salario = (salario_base + 50) - (salario_base * 0.10);

    printf("O salario atualizado do funcionario com gratificaçao e desconto doimposto eh: %.2fR$\n", novo_salario);

    return 0;
}