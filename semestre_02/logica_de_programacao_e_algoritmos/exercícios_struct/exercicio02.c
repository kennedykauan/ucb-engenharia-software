#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 15

// definicao da struct produto
typedef struct {
    int codigo;
    char nome[100];
    float preco;
    int quantidade;
} Produto;

//funcao para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//funcao para buscar o indice de um produto pelo codigo
int buscarIndicePorCodigo(Produto produtos[], int total, int codigo) {
    for (int i = 0; i < total; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

//funcao para cadastrar um novo produto
void cadastrarProduto(Produto produtos[], int *total) {
    if (*total >= MAX_PRODUTOS) {
        printf("Limite maximo de %d produtos atingido!\n", MAX_PRODUTOS);
        return;
    }

    int codigo;
    printf("Codigo do produto: ");
    scanf("%d", &codigo);
    limparBuffer();

    if (buscarIndicePorCodigo(produtos, *total, codigo) != -1) {
        printf("Erro: Codigo %d ja cadastrado!\n", codigo);
        return;
    }

    produtos[*total].codigo = codigo;

    printf("Nome do produto: ");
    fgets(produtos[*total].nome, sizeof(produtos[*total].nome), stdin);
    produtos[*total].nome[strcspn(produtos[*total].nome, "\n")] = '\0';

    printf("Preco unitario: R$ ");
    scanf("%f", &produtos[*total].preco);

    printf("Quantidade inicial em estoque: ");
    scanf("%d", &produtos[*total].quantidade);

    (*total)++;
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos(Produto produtos[], int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    float valorTotalEstoque = 0.0f;
    int idxMaiorValor = 0;
    float maiorValorItem = produtos[0].preco * produtos[0].quantidade;

    printf("\n=== LISTA DE PRODUTOS ===\n");
    for (int i = 0; i < total; i++) {
        float valorItem = produtos[i].preco * produtos[i].quantidade;
        valorTotalEstoque += valorItem;

        if (valorItem > maiorValorItem) {
            maiorValorItem = valorItem;
            idxMaiorValor = i;
        }

        printf("Cod: %d | %-20s | Preco: R$ %.2f | Qtd: %d | Subtotal: R$ %.2f\n",
               produtos[i].codigo, produtos[i].nome, produtos[i].preco,
               produtos[i].quantidade, valorItem);
    }

    printf("\nValor total de todos os produtos em estoque: R$ %.2f\n", valorTotalEstoque);
    printf("Produto com maior valor total em estoque: %s (R$ %.2f)\n",
           produtos[idxMaiorValor].nome, maiorValorItem);
}

void reporEstoque(Produto produtos[], int total) {
    int codigo, qtd;
    printf("Codigo do produto para reposicao: ");
    scanf("%d", &codigo);

    int idx = buscarIndicePorCodigo(produtos, total, codigo);
    if (idx == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Quantidade a adicionar: ");
    scanf("%d", &qtd);

    if (qtd <= 0) {
        printf("Quantidade invalida.\n");
        return;
    }

    produtos[idx].quantidade += qtd;
    printf("Estoque atualizado! Nova quantidade de '%s': %d\n",
           produtos[idx].nome, produtos[idx].quantidade);
}

void registrarVenda(Produto produtos[], int total) {
    int codigo, qtd;
    printf("Codigo do produto vendido: ");
    scanf("%d", &codigo);

    int idx = buscarIndicePorCodigo(produtos, total, codigo);
    if (idx == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Quantidade vendida (Disponivel: %d): ", produtos[idx].quantidade);
    scanf("%d", &qtd);

    if (qtd <= 0) {
        printf("Quantidade invalida.\n");
        return;
    }

    if (qtd > produtos[idx].quantidade) {
        printf("Erro: Estoque insuficiente! Venda cancelada.\n");
        return;
    }

    produtos[idx].quantidade -= qtd;
    printf("Venda registrada! Total: R$ %.2f | Estoque restante: %d\n",
           qtd * produtos[idx].preco, produtos[idx].quantidade);
}

void consultarProduto(Produto produtos[], int total) {
    int codigo;
    printf("Codigo do produto para consulta: ");
    scanf("%d", &codigo);

    int idx = buscarIndicePorCodigo(produtos, total, codigo);
    if (idx == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("\n--- Detalhes do Produto ---\n");
    printf("Codigo: %d\nNome: %s\nPreco: R$ %.2f\nEstoque: %d\nValor em estoque: R$ %.2f\n",
           produtos[idx].codigo, produtos[idx].nome, produtos[idx].preco,
           produtos[idx].quantidade, produtos[idx].preco * produtos[idx].quantidade);
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcao;

    do {
        printf("\n=== MENU PAPELARIA ===\n");
        printf("1. Cadastrar produto\n");
        printf("2. Listar produtos (e totais de estoque)\n");
        printf("3. Repor estoque\n");
        printf("4. Registrar venda\n");
        printf("5. Consultar produto pelo codigo\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarProduto(produtos, &totalProdutos); break;
            case 2: listarProdutos(produtos, totalProdutos); break;
            case 3: reporEstoque(produtos, totalProdutos); break;
            case 4: registrarVenda(produtos, totalProdutos); break;
            case 5: consultarProduto(produtos, totalProdutos); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}