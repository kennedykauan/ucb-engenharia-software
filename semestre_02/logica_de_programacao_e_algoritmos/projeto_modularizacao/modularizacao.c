#include <stdio.h>
#include <string.h>

//FUNCOES (modularizacao)

// Procura um codigo no vetor. Retorna o indice ou -1 se nao achar
int buscarIndice(int codigo[], int total, int busca) {
    int i;
    for (i = 0; i < total; i++) {
        if (codigo[i] == busca) {
            return i;
        }
    }
    return -1;
}

// Le um nome do teclado e remove o \n que o fgets deixa no final
void lerNome(char destino[]) {
    fgets(destino, 15, stdin);
    destino[strcspn(destino, "\n")] = '\0';
}

// Mostra um unico registro na tela
void mostrarRegistro(int codigo, char nome[]) {
    printf("Codigo: %d | Nome: %s\n", codigo, nome);
}

// ===== FUNCOES DO CADASTRO =====

// 1 - CADASTRAR: insere um registro por vez
void cadastrar(int codigo[], char nome[][15], int *total) {
    if (*total == 5) {
        printf("\nCadastro cheio!\n");
        return;
    }
    printf("\nDigite o codigo: ");
    scanf("%d", &codigo[*total]);
    getchar(); // limpa o \n que sobrou no buffer
    printf("Digite o nome: ");
    lerNome(nome[*total]);
    (*total)++;
    printf("\nCadastro realizado com sucesso!\n");
}

// 2 - CONSULTAR: procura um codigo e mostra o registro
void consultar(int codigo[], char nome[][15], int total) {
    int busca;
    int i;

    printf("\nDigite o codigo para consulta: ");
    scanf("%d", &busca);

    i = buscarIndice(codigo, total, busca);
    if (i != -1) {
        printf("\n");
        mostrarRegistro(codigo[i], nome[i]);
    } else {
        printf("\nCodigo nao encontrado!\n");
    }
}

// 3 - LISTAR: mostra todos os registros cadastrados
void listar(int codigo[], char nome[][15], int total) {
    int i;

    if (total == 0) {
        printf("\nNenhum registro cadastrado!\n");
        return;
    }

    printf("\n--- REGISTROS CADASTRADOS ---\n");
    for (i = 0; i < total; i++) {
        mostrarRegistro(codigo[i], nome[i]);
    }
}

// 4 - ALTERAR: procura um codigo e troca codigo e nome
void alterar(int codigo[], char nome[][15], int total) {
    int busca;
    int i;

    printf("\nDigite o codigo que sera alterado: ");
    scanf("%d", &busca);

    i = buscarIndice(codigo, total, busca);
    if (i != -1) {
        printf("Digite o novo codigo: ");
        scanf("%d", &codigo[i]);
        getchar();
        printf("Digite o novo nome: ");
        lerNome(nome[i]);
        printf("\nRegistro alterado com sucesso!\n");
    } else {
        printf("\nCodigo nao encontrado!\n");
    }
}

// 5 - EXCLUIR: remove um registro e fecha o "buraco" no vetor
void excluir(int codigo[], char nome[][15], int *total) {
    int busca;
    int i;
    int j;

    printf("\nDigite o codigo que sera excluido: ");
    scanf("%d", &busca);

    i = buscarIndice(codigo, *total, busca);
    if (i != -1) {
        // Desloca os registros seguintes uma posicao para a esquerda
        for (j = i; j < *total - 1; j++) {
            codigo[j] = codigo[j + 1];
            strcpy(nome[j], nome[j + 1]);
        }
        (*total)--;
        printf("\nRegistro excluido com sucesso!\n");
    } else {
        printf("\nCodigo nao encontrado!\n");
    }
}

// ===== PROGRAMA PRINCIPAL =====
int main(void) {
    int codigo[5];
    char nome[5][15];
    int total = 0;
    int opcao;

    do {
        printf("\n\n===== MENU =====");
        printf("\n1 - Cadastrar");
        printf("\n2 - Consultar");
        printf("\n3 - Listar");
        printf("\n4 - Alterar");
        printf("\n5 - Excluir");
        printf("\n0 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar(codigo, nome, &total);
                break;
            case 2:
                consultar(codigo, nome, total);
                break;
            case 3:
                listar(codigo, nome, total);
                break;
            case 4:
                alterar(codigo, nome, total);
                break;
            case 5:
                excluir(codigo, nome, &total);
                break;
            case 0:
                printf("\nEncerrando...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}