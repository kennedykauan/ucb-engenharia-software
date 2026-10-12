#include<stdio.h>

int main(){
    float salario, aumento, novo_salario;

    printf("Digite o valor do salario do funcionario: ");
    scanf("%f", &salario);

    printf("Digite o valor do aumento em porcentagem: ");
    scanf("%f", &aumento);

    novo_salario = salario * (aumento / 100);

    printf("O aumento do salario do funcionario foi de : %.2fR$\n", novo_salario);
    printf("O novo salario do funcionario eh: %.2fR$\n", salario + novo_salario);


    return 0;
}