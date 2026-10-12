#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    char continuar = 's';
    int total_clientes = 0;
    int total_recusados = 0;
    int total_analise = 0;
    int total_aprovados = 0;
    
    printf("Seja bem-vindo(a) à concessionária Kennedyzz\n");

    while (continuar == 's' || continuar == 'S') {

        char nome[50];
        float renda, preco_do_carro;
        int renda_inteiro, situacao;
        
        printf("\n--- Novo Cadastro ---\n");
        printf("Digite o seu nome: ");
        scanf(" %[^\n]", nome);
        
        printf("Digite a sua renda: ");
        scanf("%f", &renda);
        renda_inteiro = (int)renda;
        
        printf("Digite o valor do veículo: ");
        scanf("%f", &preco_do_carro);

        printf("\nOlá %s\nSua renda é R$ %.2f\nO valor do veículo desejado é: R$ %.2f\n", nome, renda, preco_do_carro);

        if (renda < (preco_do_carro / 36)) {
            printf("Crédito recusado.\n");
            printf("Infelizmente você não possui renda suficiente para adquirir o veículo desejado.\n");
            total_recusados++;
        } 

        else {

            if (renda_inteiro <= 2000) {
                situacao = 1;
            } 

            else if (renda_inteiro <= 3000) {
                situacao = 2;
            } 

            else {
                situacao = 3;
            }


            switch (situacao) {

                case 1:
                    printf("Cliente sujeito a análise de crédito.\n");
                    total_analise++;
                    break;

                case 2:
                    printf("Cliente aprovado para o financiamento.\n");
                    total_aprovados++;
                    break;

                case 3:
                    printf("Cliente aprovado para o financiamento (renda acima da faixa padrão).\n");
                    total_aprovados++;
                    break;
            }
        }
        
        total_clientes++;
        
        printf("\nDeseja analisar outro cliente? (s/n): ");
        scanf(" %c", &continuar);
    }

    // system("cls");
    
    printf("\n----------------------------------------\n");
    printf("          RELATÓRIO FINAL               \n");
    printf("----------------------------------------\n");
    printf("Total de clientes processados: %d\n", total_clientes);
    printf(" - Créditos aprovados: %d\n", total_aprovados);
    printf(" - Sujeitos a análise: %d\n", total_analise);
    printf(" - Créditos recusados: %d\n", total_recusados);
    printf("----------------------------------------\n");
    printf("Fim. Obrigado!\n");

    return 0;
}