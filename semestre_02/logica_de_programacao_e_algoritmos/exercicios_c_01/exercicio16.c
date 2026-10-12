#include <stdio.h>

int main() {
    float horas_trabalhadas, salario_minimo;
    float valor_hora, salario_bruto, imposto, salario_receber;
    
    printf("Digite as horas trabalhadas e o valor do salario minimo: ");
    scanf("%f %f", &horas_trabalhadas, &salario_minimo);
    
    valor_hora = salario_minimo / 2.0;
    salario_bruto = horas_trabalhadas * valor_hora;
    imposto = salario_bruto * 0.03;
    salario_receber = salario_bruto - imposto;
    
    printf("Salario a receber: R$ %.2f\n", salario_receber);
    
    return 0;
}