#include <stdio.h>

int main() {
    float preco_etiqueta, valor_final;
    int codigo_pagamento;

    printf("Digite o preco normal de etiqueta: R$ ");
    scanf("%f", &preco_etiqueta);

    printf("\n--- Codigos de Pagamento ---\n");
    printf("1 - A vista em dinheiro/cheque (10%% de desconto)\n");
    printf("2 - A vista no cartao de credito (15%% de desconto)\n");
    printf("3 - Em duas parcelas (preco normal, sem juros)\n");
    printf("4 - Em duas parcelas (acrescimo de 10%%)\n");
    printf("Digite o codigo da condicao de pagamento: ");
    scanf("%d", &codigo_pagamento);

    switch (codigo_pagamento) {
        case 1:
            valor_final = preco_etiqueta * 0.90; // 10% de desconto
            printf("\nValor final a ser pago: R$ %.2f\n", valor_final);
            break;

        case 2:
            valor_final = preco_etiqueta * 0.85; // 15% de desconto
            printf("\nValor final a ser pago: R$ %.2f\n", valor_final);
            break;

        case 3:
            valor_final = preco_etiqueta; // normal
            printf("\nValor final a ser pago: R$ %.2f (2x de R$ %.2f)\n", valor_final, valor_final / 2);
            break;

        case 4:
            valor_final = preco_etiqueta * 1.10; // 10% de acréscimo
            printf("\nValor final a ser pago: R$ %.2f (2x de R$ %.2f)\n", valor_final, valor_final / 2);
            break;

        default:
            printf("\nCodigo de pagamento invalido!\n");
            break;
    }

    return 0;
}