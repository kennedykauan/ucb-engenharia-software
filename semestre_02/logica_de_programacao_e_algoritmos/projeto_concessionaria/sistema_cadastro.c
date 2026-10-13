#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 20

int main() {
  // Configura o terminal do Windows para UTF-8 (permite ç, acentos e caracteres
  // especiais)
  system("chcp 65001 > nul");

  // Vetores paralelos para armazenar os dados dos produtos
  int codigo[TAM_MAX];
  char nome[TAM_MAX][50];
  float preco[TAM_MAX];
  int quantidade[TAM_MAX];

  // Variaveis de controle
  int total = 0;        // Quantidade de produtos cadastrados
  int opcao;            // Opcao do menu
  int i, j;             // Variaveis para os lacos de repeticao
  int codigoBusca;      // Codigo informado para consulta, alteracao ou exclusao
  int posicao;          // Posicao do produto encontrado no vetor
  int encontrado;       // Variavel para indicar se o produto foi achado
  int c;                // Variavel auxiliar para limpar o buffer do teclado
  float subtotal;       // Preço vezes quantidade por produto
  float totalAcumulado; // Total em preço acumulado de todos os produtos

  do {
    // Limpa a tela antes de exibir o menu
    system("cls");

    printf("=========================================\n");
    printf("     SISTEMA DE CADASTRO DE PRODUTOS     \n");
    printf("=========================================\n");
    printf("1 - Cadastrar\n");
    printf("2 - Consultar\n");
    printf("3 - Listar\n");
    printf("4 - Alterar\n");
    printf("5 - Excluir\n");
    printf("0 - Sair\n");
    printf("=========================================\n");
    printf("Escolha uma opção: ");

    // Valida para aceitar apenas numero na opcao
    while (scanf("%d", &opcao) != 1) {
      printf("Opção inválida! Digite apenas números: ");
      while ((c = getchar()) != '\n' && c != EOF)
        ; // Limpa caracteres invalidos do teclado
    }

    switch (opcao) {
    // -------------------------------------------------------------
    // 1. CADASTRAR (0,4 ponto)
    // -------------------------------------------------------------
    case 1:
      system("cls");
      printf("=========================================\n");
      printf("          CADASTRAR PRODUTO              \n");
      printf("=========================================\n");

      // Verifica se o vetor esta cheio
      if (total >= TAM_MAX) {
        printf("Limite máximo de cadastros atingido.\n");
      } else {
        printf("Digite o código: ");
        // Garante que o codigo seja apenas numero positivo
        while (scanf("%d", &codigo[total]) != 1 || codigo[total] <= 0) {
          printf("Código inválido! Digite apenas números: ");
          while ((c = getchar()) != '\n' && c != EOF)
            ; // Descarta letras ou caracteres invalidos
        }

        printf("Digite o nome: ");
        scanf(" %49[^\n]", nome[total]);

        printf("Digite o preço: R$ ");
        // Garante que o preco seja apenas numero
        while (scanf("%f", &preco[total]) != 1 || preco[total] < 0) {
          printf("Preço inválido! Digite apenas números: R$ ");
          while ((c = getchar()) != '\n' && c != EOF)
            ;
        }

        printf("Digite a quantidade: ");
        // Garante que a quantidade seja apenas numero inteiro
        while (scanf("%d", &quantidade[total]) != 1 || quantidade[total] < 0) {
          printf("Quantidade inválida! Digite apenas números: ");
          while ((c = getchar()) != '\n' && c != EOF)
            ;
        }

        total++;
        subtotal = preco[total - 1] * quantidade[total - 1];
        printf("\nProduto cadastrado com sucesso! Total em valor: R$ %.2f\n",
               subtotal);
      }

      printf("\nPressione ENTER para continuar...");
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      getchar();
      break;

    // -------------------------------------------------------------
    // 2. CONSULTAR (0,4 ponto)
    // -------------------------------------------------------------
    case 2:
      system("cls");
      printf("=========================================\n");
      printf("          CONSULTAR PRODUTO              \n");
      printf("=========================================\n");

      if (total == 0) {
        printf("Registro não encontrado.\n");
      } else {
        printf("Digite o código para consulta: ");
        while (scanf("%d", &codigoBusca) != 1 || codigoBusca <= 0) {
          printf("Código inválido! Digite apenas números: ");
          while ((c = getchar()) != '\n' && c != EOF)
            ;
        }

        encontrado = 0;
        for (i = 0; i < total; i++) {
          if (codigo[i] == codigoBusca) {
            subtotal = preco[i] * quantidade[i];
            printf("\nCódigo: %d\n", codigo[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Preço: R$ %.2f\n", preco[i]);
            printf("Quantidade: %d\n", quantidade[i]);
            printf("Total em valor: R$ %.2f\n", subtotal);
            encontrado = 1;
            break;
          }
        }

        if (!encontrado) {
          printf("\nRegistro não encontrado.\n");
        }
      }

      printf("\nPressione ENTER para continuar...");
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      getchar();
      break;

    // -------------------------------------------------------------
    // 3. LISTAR (0,4 ponto)
    // -------------------------------------------------------------
    case 3:
      system("cls");
      printf("=========================================\n");
      printf("          LISTA DE PRODUTOS              \n");
      printf("=========================================\n");

      if (total == 0) {
        printf("Nenhum registro cadastrado.\n");
      } else {
        totalAcumulado = 0.0f;
        for (i = 0; i < total; i++) {
          subtotal = preco[i] * quantidade[i];
          totalAcumulado += subtotal;

          printf("\nCódigo: %d\n", codigo[i]);
          printf("Nome: %s\n", nome[i]);
          printf("Preço: R$ %.2f\n", preco[i]);
          printf("Quantidade: %d\n", quantidade[i]);
          printf("Total em valor: R$ %.2f\n", subtotal);
          printf("-----------------------------------------\n");
        }
        printf("Total de registros cadastrados: %d\n", total);
        printf("Total em preço acumulado: R$ %.2f\n", totalAcumulado);
      }

      printf("\nPressione ENTER para continuar...");
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      getchar();
      break;

    // -------------------------------------------------------------
    // 4. ALTERAR (0,4 ponto)
    // -------------------------------------------------------------
    case 4:
      system("cls");
      printf("=========================================\n");
      printf("          ALTERAR PRODUTO                \n");
      printf("=========================================\n");

      if (total == 0) {
        printf("Registro não encontrado.\n");
      } else {
        printf("Digite o código do produto a alterar: ");
        while (scanf("%d", &codigoBusca) != 1 || codigoBusca <= 0) {
          printf("Código inválido! Digite apenas números: ");
          while ((c = getchar()) != '\n' && c != EOF)
            ;
        }

        posicao = -1;
        for (i = 0; i < total; i++) {
          if (codigo[i] == codigoBusca) {
            posicao = i;
            break;
          }
        }

        if (posicao == -1) {
          printf("\nRegistro não encontrado.\n");
        } else {
          subtotal = preco[posicao] * quantidade[posicao];
          printf("\nDados atuais do produto:\n");
          printf("Código: %d\n", codigo[posicao]);
          printf("Nome: %s\n", nome[posicao]);
          printf("Preço: R$ %.2f\n", preco[posicao]);
          printf("Quantidade: %d\n", quantidade[posicao]);
          printf("Total em valor: R$ %.2f\n", subtotal);

          printf("\nDigite os novos dados:\n");
          printf("Novo nome: ");
          scanf(" %49[^\n]", nome[posicao]);

          printf("Novo preço: R$ ");
          while (scanf("%f", &preco[posicao]) != 1 || preco[posicao] < 0) {
            printf("Preço inválido! Digite apenas números: R$ ");
            while ((c = getchar()) != '\n' && c != EOF)
              ;
          }

          printf("Nova quantidade: ");
          while (scanf("%d", &quantidade[posicao]) != 1 ||
                 quantidade[posicao] < 0) {
            printf("Quantidade inválida! Digite apenas números: ");
            while ((c = getchar()) != '\n' && c != EOF)
              ;
          }

          subtotal = preco[posicao] * quantidade[posicao];
          printf(
              "\nCadastro alterado com sucesso! Novo total em valor: R$ %.2f\n",
              subtotal);
        }
      }

      printf("\nPressione ENTER para continuar...");
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      getchar();
      break;

    // -------------------------------------------------------------
    // 5. EXCLUIR (0,4 ponto)
    // -------------------------------------------------------------
    case 5:
      system("cls");
      printf("=========================================\n");
      printf("          EXCLUIR PRODUTO                \n");
      printf("=========================================\n");

      if (total == 0) {
        printf("Não foi possível excluir.\n");
      } else {
        printf("Digite o código do produto a excluir: ");
        while (scanf("%d", &codigoBusca) != 1 || codigoBusca <= 0) {
          printf("Código inválido! Digite apenas números: ");
          while ((c = getchar()) != '\n' && c != EOF)
            ;
        }

        posicao = -1;
        for (i = 0; i < total; i++) {
          if (codigo[i] == codigoBusca) {
            posicao = i;
            break;
          }
        }

        if (posicao == -1) {
          printf("\nNão foi possível excluir.\n");
        } else {
          // Desloca os registros da frente para cobrir o excluido
          for (i = posicao; i < total - 1; i++) {
            codigo[i] = codigo[i + 1];
            preco[i] = preco[i + 1];
            quantidade[i] = quantidade[i + 1];
            for (j = 0; j < 50; j++) {
              nome[i][j] = nome[i + 1][j];
            }
          }
          total--;
          printf("\nRegistro excluído com sucesso!\n");
        }
      }

      printf("\nPressione ENTER para continuar...");
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      getchar();
      break;

    // -------------------------------------------------------------
    // 0. SAIR DO SISTEMA
    // -------------------------------------------------------------
    case 0:
      printf("\nEncerrando o programa... Até logo!\n");
      break;

    // -------------------------------------------------------------
    // OPCAO INVALIDA
    // -------------------------------------------------------------
    default:
      printf("\nOpção inválida.\n");
      printf("\nPressione ENTER para continuar...");
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      getchar();
      break;
    }

  } while (opcao != 0);

  return 0;
}
