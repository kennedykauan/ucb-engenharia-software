#include <stdio.h>
#include <math.h>

char menuOpcoes(double total){
    char opcao;
    printf("\nOpcoes de pagamento:\n");
    printf("a) A vista com 10%% de desconto\n");
    printf("b) Em duas vezes (preco da etiqueta)\n");
    if (total > 100.0)
        printf("c) De 3 ate 10 vezes com 3%% de juros ao mes\n");
    printf("Escolha a opcao: ");
    scanf(" %c", &opcao);
    return opcao;
}

void pagamentoAVista(double total){
    printf("Valor a vista: R$ %.2f\n", total * 0.90);
}

void pagamentoDuasVezes(double total){
    printf("2 parcelas de R$ %.2f (total R$ %.2f)\n", total / 2.0, total);
}

void pagamentoParcelado(double total){
    int n;
    double final;

    if (total <= 100.0) {
        printf("Opcao disponivel apenas para compras acima de R$ 100,00.\n");
        return;
    }
    do {
        printf("Numero de parcelas (3 a 10): ");
        scanf("%d", &n);
    } while (n < 3 || n > 10);

    final = total * pow(1.03, n);
    printf("%d parcelas de R$ %.2f (total R$ %.2f)\n", n, final / n, final);
}

int main(void){
    double total;
    char opcao;

    printf("Digite o total gasto: R$ ");
    scanf("%lf", &total);

    opcao = menuOpcoes(total);

    switch (opcao) {
    case 'a':
    case 'A':
        pagamentoAVista(total);
        break;
    case 'b':
    case 'B':
        pagamentoDuasVezes(total);
        break;
    case 'c':
    case 'C':
        pagamentoParcelado(total);
        break;
    default:
        printf("Opcao invalida.\n");
    }
    return 0;
}
