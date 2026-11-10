#include <stdio.h>
#include <string.h>

// 1 - CADASTRAR: insere um registro por vez
void cadastrar(int codigo[], char nome[][15], int *total) {

    // Maximo de 5 registros, se ja tiver 5, nao cadastra mais
    if (*total == 5) {
        printf("\nCadastro cheio!\n");
        return;
    }

    // Le o codigo e guarda na proxima posicao livre (indice = total)
    printf("\nDigite o codigo: ");
    scanf("%d", &codigo[*total]);
    getchar(); // limpa o \n que sobrou no buffer depois do scanf
    // Le o nome na mesma posicao

    printf("Digite o nome: ");
    fgets(nome[*total], 15, stdin);

    // Remove o \n que o fgets guarda no final da string
    nome[*total][strcspn(nome[*total], "\n")] = '\0';

    // Aumenta o total de registros (por isso recebe ponteiro)
    (*total)++;
    printf("\nCadastro realizado com sucesso!\n");
}

// 2 - CONSULTAR: procura um codigo e mostra o registro
void consultar(int codigo[], char nome[][15], int total) {
    int busca;
    int i;
    int achou = 0; // 0 = nao encontrou, 1 = encontrou

    // Pede o codigo que sera procurado
    printf("\nDigite o codigo para consulta: ");
    scanf("%d", &busca);

    // Percorre apenas os registros que existem (0 ate total - 1)
    for (i = 0; i < total; i++) {
        if (codigo[i] == busca) {
            printf("\nCodigo: %d", codigo[i]);
            printf("\nNome: %s\n", nome[i]);
            achou = 1;
            break; // ja achou, nao precisa continuar procurando
        }
    }

    // Se o laco terminou e nao achou nada, avisa o usuario
    if (!achou) {
        printf("\nCodigo nao encontrado!\n");
    }
}

// 3 - LISTAR: mostra todos os registros cadastrados
void listar(int codigo[], char nome[][15], int total) {
    int i;

    // Se nao tem nenhum registro, avisa e sai da funcao
    if (total == 0) {
        printf("\nNenhum registro cadastrado!\n");
        return;
    }

    // Mostra codigo e nome de cada registro
    printf("\n--- REGISTROS CADASTRADOS ---\n");
    for (i = 0; i < total; i++) {
        printf("Codigo: %d | Nome: %s\n", codigo[i], nome[i]);
    }
}

// 4 - ALTERAR: procura um codigo e troca codigo e nome
void alterar(int codigo[], char nome[][15], int total) {
    int busca;
    int i;
    int achou = 0;

    // Pede o codigo do registro que sera alterado
    printf("\nDigite o codigo que sera alterado: ");
    scanf("%d", &busca);

    for (i = 0; i < total; i++) {

        if (codigo[i] == busca) {

            // Achou: le os novos dados e sobrescreve na mesma posicao i
            printf("Digite o novo codigo: ");
            scanf("%d", &codigo[i]);
            getchar(); // limpa o buffer

            printf("Digite o novo nome: ");
            fgets(nome[i], 15, stdin);
            nome[i][strcspn(nome[i], "\n")] = '\0'; // tira o \n do nome

            printf("\nRegistro alterado com sucesso!\n");
            achou = 1;
            break;
        }
    }

    if (!achou) {
        printf("\nCodigo nao encontrado!\n");
    }
}

// 5 - EXCLUIR: remove um registro e fecha o "buraco" no vetor
void excluir(int codigo[], char nome[][15], int *total) {
    int busca;
    int i;
    int j;
    int achou = 0;

    // Pede o codigo do registro que sera excluido
    printf("\nDigite o codigo que sera excluido: ");
    scanf("%d", &busca);

    for (i = 0; i < *total; i++) {

        if (codigo[i] == busca) {
            // Desloca os registros seguintes uma posicao para a esquerda,
            // sobrescrevendo o registro que esta sendo excluido

            for (j = i; j < *total - 1; j++) {
                codigo[j] = codigo[j + 1];          // copia o codigo (int usa =)
                strcpy(nome[j], nome[j + 1]);       // copia o nome (string usa strcpy)
            }

            (*total)--; // diminui a quantidade de registros
            printf("\nRegistro excluido com sucesso!\n");
            achou = 1;
            break;
        }
    }

    if (!achou) {
        printf("\nCodigo nao encontrado!\n");}
}