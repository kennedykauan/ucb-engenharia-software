#include <stdio.h>
#include <string.h>

#define MAX_FUNC 8
#define HORAS_MENSAIS 160.0f

typedef struct {
    int codigo;
    char nome[100];
    char cargo[60];
    float salarioBase;
    float horasExtras;
} Funcionario;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Funcionario funcs[MAX_FUNC];
    int qtd;

    do {
        printf("Quantos funcionarios deseja cadastrar (1 a %d)? ", MAX_FUNC);
        scanf("%d", &qtd);
    } while (qtd < 1 || qtd > MAX_FUNC);

    for (int i = 0; i < qtd; i++) {
        printf("\n=== Funcionario %d ===\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &funcs[i].codigo);
        limparBuffer();

        printf("Nome: ");
        fgets(funcs[i].nome, sizeof(funcs[i].nome), stdin);
        funcs[i].nome[strcspn(funcs[i].nome, "\n")] = '\0';

        printf("Cargo: ");
        fgets(funcs[i].cargo, sizeof(funcs[i].cargo), stdin);
        funcs[i].cargo[strcspn(funcs[i].cargo, "\n")] = '\0';

        printf("Salario-base: R$ ");
        scanf("%f", &funcs[i].salarioBase);

        printf("Quantidade de horas extras: ");
        scanf("%f", &funcs[i].horasExtras);
    }

    float maiorSalarioLiquido = -1.0f;
    int idxMaior = 0;
    float custoTotalBruto = 0.0f;
    float custoTotalLiquido = 0.0f;

    printf("\n=== FOLHA DE PAGAMENTO ===\n");
    for (int i = 0; i < qtd; i++) {
        float valorHora = funcs[i].salarioBase / HORAS_MENSAIS;
        float valorHoraExtra = valorHora * 1.5f;
        float totalExtras = funcs[i].horasExtras * valorHoraExtra;
        float salarioBruto = funcs[i].salarioBase + totalExtras;
        float desconto = salarioBruto * 0.10f;
        float salarioLiquido = salarioBruto - desconto;

        custoTotalBruto += salarioBruto;
        custoTotalLiquido += salarioLiquido;

        if (salarioLiquido > maiorSalarioLiquido) {
            maiorSalarioLiquido = salarioLiquido;
            idxMaior = i;
        }

        printf("\nCod: %d | %s (%s)\n", funcs[i].codigo, funcs[i].nome, funcs[i].cargo);
        printf("  Valor Hora: R$ %.2f | Valor Hora Extra (+50%%): R$ %.2f\n", valorHora, valorHoraExtra);
        printf("  Salario Bruto: R$ %.2f | Desconto (10%%): R$ %.2f | Salario Liquido: R$ %.2f\n",
               salarioBruto, desconto, salarioLiquido);
    }

    printf("\n=== RESUMO DA FOLHA ===\n");
    printf("Maior salario liquido: %s (R$ %.2f)\n", funcs[idxMaior].nome, maiorSalarioLiquido);
    printf("Custo total da folha (Bruto): R$ %.2f\n", custoTotalBruto);
    printf("Custo total da folha (Liquido): R$ %.2f\n", custoTotalLiquido);

    return 0;
}