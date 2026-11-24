#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 10
#define MAX_VENDAS 20

typedef struct {
    int codigo;
    char nome[100];
    float preco;
    int estoque;
} Produto;

typedef struct {
    Produto produto;
    int quantidade;
    float valorTotal;
} Venda;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int buscarProduto(Produto produtos[], int total, int codigo) {
    for (int i = 0; i < total; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    Venda vendas[MAX_VENDAS];
    int totalProdutos = 0, totalVendas = 0;
    int opcao;

    do {
        printf("\n=== SISTEMA DE VENDAS ===\n");
        printf("1. Cadastrar produto (%d/%d)\n", totalProdutos, MAX_PRODUTOS);
        printf("2. Registrar venda (%d/%d)\n", totalVendas, MAX_VENDAS);
        printf("3. Relatorio de faturamento e estoque\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (totalProdutos >= MAX_PRODUTOS) {
                printf("Limite de produtos atingido!\n");
                continue;
            }
            int cod;
            printf("Codigo do produto: ");
            scanf("%d", &cod);
            limparBuffer();

            if (buscarProduto(produtos, totalProdutos, cod) != -1) {
                printf("Codigo ja cadastrado!\n");
                continue;
            }

            produtos[totalProdutos].codigo = cod;
            printf("Nome: ");
            fgets(produtos[totalProdutos].nome, sizeof(produtos[totalProdutos].nome), stdin);
            produtos[totalProdutos].nome[strcspn(produtos[totalProdutos].nome, "\n")] = '\0';

            printf("Preco: R$ ");
            scanf("%f", &produtos[totalProdutos].preco);

            printf("Estoque inicial: ");
            scanf("%d", &produtos[totalProdutos].estoque);

            totalProdutos++;
            printf("Produto cadastrado!\n");

        } else if (opcao == 2) {
            if (totalVendas >= MAX_VENDAS) {
                printf("Limite de vendas atingido!\n");
                continue;
            }
            if (totalProdutos == 0) {
                printf("Cadastre ao menos um produto antes de vender.\n");
                continue;
            }

            int cod, qtd;
            printf("Codigo do produto: ");
            scanf("%d", &cod);

            int idx = buscarProduto(produtos, totalProdutos, cod);
            if (idx == -1) {
                printf("Produto nao encontrado!\n");
                continue;
            }

            printf("Quantidade (Disponivel: %d): ", produtos[idx].estoque);
            scanf("%d", &qtd);

            if (qtd <= 0 || qtd > produtos[idx].estoque) {
                printf("Quantidade invalida ou estoque insuficiente!\n");
                continue;
            }

            produtos[idx].estoque -= qtd;

            vendas[totalVendas].produto = produtos[idx];
            vendas[totalVendas].quantidade = qtd;
            vendas[totalVendas].valorTotal = qtd * produtos[idx].preco;

            printf("Venda registrada! Valor total: R$ %.2f\n", vendas[totalVendas].valorTotal);
            totalVendas++;

        } else if (opcao == 3) {
            float faturamentoTotal = 0.0f;
            float faturamentoPorProduto[MAX_PRODUTOS] = {0};

            for (int i = 0; i < totalVendas; i++) {
                faturamentoTotal += vendas[i].valorTotal;
                int idxProd = buscarProduto(produtos, totalProdutos, vendas[i].produto.codigo);
                if (idxProd != -1) {
                    faturamentoPorProduto[idxProd] += vendas[i].valorTotal;
                }
            }

            printf("\n=== RELATORIO GERAL ===\n");
            printf("Faturamento total: R$ %.2f\n", faturamentoTotal);

            if (totalVendas > 0 && totalProdutos > 0) {
                int idxCampeao = 0;
                for (int i = 1; i < totalProdutos; i++) {
                    if (faturamentoPorProduto[i] > faturamentoPorProduto[idxCampeao]) {
                        idxCampeao = i;
                    }
                }
                printf("Produto com maior faturamento: %s (R$ %.2f)\n",
                       produtos[idxCampeao].nome, faturamentoPorProduto[idxCampeao]);
            }

            printf("\nEstoque atual:\n");
            for (int i = 0; i < totalProdutos; i++) {
                printf("  Cod: %d | %-18s | Estoque: %d | Faturado: R$ %.2f\n",
                       produtos[i].codigo, produtos[i].nome, produtos[i].estoque, faturamentoPorProduto[i]);
            }
        }
    } while (opcao != 0);

    return 0;
}