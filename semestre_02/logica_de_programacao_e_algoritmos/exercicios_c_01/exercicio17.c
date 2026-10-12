#include <stdio.h>

int main() {
    float salario, cheque1, cheque2, cpmf1, cpmf2, saldo_final;

    printf("Digite o salario recebido (deposito): ");
    scanf("%f", &salario);

    printf("Digite o valor dos dois cheques emitidos: ");
    scanf("%f %f", &cheque1, &cheque2);
    
    cpmf1 = cheque1 * 0.0038;
    cpmf2 = cheque2 * 0.0038;
    saldo_final = salario - (cheque1 + cpmf1) - (cheque2 + cpmf2);
    
    printf("Saldo atual da conta: R$ %.2f\n", saldo_final);
    
    return 0;
    
}