#include <stdio.h>

int main() {
    int codigo;

    printf("Codigo | Prato                   | Valor\n");
    printf("------------------------------------------\n");
    printf("  1    | Hamburguer com fritas   | R$ 28,00\n");
    printf("  2    | File de frango grelhado | R$ 32,00\n");
    printf("  3    | Lasanha a bolonhesa     | R$ 35,00\n");
    printf("  4    | File de peixe com arroz | R$ 42,00\n");
    printf("  5    | Salada especial         | R$ 25,00\n");
    printf("------------------------------------------\n");

    printf("Digite o codigo do prato desejado: ");
    scanf("%d", &codigo);
    printf("\n");


    switch (codigo) {
        case 1:
            printf("Prato escolhido: Hamburguer com fritas\n");
            printf("Valor: R$ 28,00\n");
            break;

        case 2:
            printf("Prato escolhido: File de frango grelhado\n");
            printf("Valor: R$ 32,00\n");
            break;

        case 3:
            printf("Prato escolhido: Lasanha a bolonhesa\n");
            printf("Valor: R$ 35,00\n");
            break;

        case 4:
            printf("Prato escolhido: File de peixe com arroz\n");
            printf("Valor: R$ 42,00\n");
            break;

        case 5:
            printf("Prato escolhido: Salada especial\n");
            printf("Valor: R$ 25,00\n");
            break;
            
        default:
            printf("Opcao invalida\n");
            break;
    }

    return 0;
}