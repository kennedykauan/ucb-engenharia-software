/*
 * SISTEMA DE ATENDIMENTO PARA PETSHOP
 * Bibliotecas: stdio.h (printf, sprintf, getchar), string.h (strcmp, strcpy), stdlib.h (atoi)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 100
#define TAM_TEXTO 50
#define USUARIO "admin"
#define SENHA "1234"

/* ---------- DADOS DO ATENDIMENTO ---------- */
char funcionario[TAM_TEXTO];
char clienteNome[TAM_TEXTO], clienteTelefone[TAM_TEXTO];
char petNome[TAM_TEXTO], petEspecie[TAM_TEXTO], petRaca[TAM_TEXTO], petPorte[TAM_TEXTO];
int clienteCadastrado = 0, petCadastrado = 0;
int petPorteCodigo = 0; /* 1 = pequeno, 2 = medio, 3 = grande */

/* Vetores paralelos: o item i usa a posicao i dos tres vetores */
char itemDescricao[MAX_ITENS][TAM_TEXTO];
int itemQuantidade[MAX_ITENS];
float itemValor[MAX_ITENS];
int totalItens = 0;

/* ---------- TEXTOS DOS MENUS ---------- */
char itensPrincipal[4][TAM_TEXTO] = {"Cadastros", "Servicos", "Produtos", "Comprovante"};
char itensCadastros[2][TAM_TEXTO] = {"Cadastrar cliente", "Cadastrar pet"};
char itensServicos[3][TAM_TEXTO] = {"Banho", "Tosa", "Veterinaria"};
char itensTosa[3][TAM_TEXTO] = {"Tosa higienica", "Tosa completa", "Tosa na tesoura"};
char itensVet[3][TAM_TEXTO] = {"Consulta", "Vacina", "Exame"};

/* ---------- PRODUTOS ----------
   Categoria 0 = Alimentos, 1 = Acessorios, 2 = Higiene.
   O preco em precosProdutos[c][p] pertence ao nome em nomesProdutos[c][p] */
char categorias[3][TAM_TEXTO] = {"Alimentos", "Acessorios", "Higiene"};
char nomesProdutos[3][3][TAM_TEXTO] = {
    {"Racao caes 10kg", "Racao gatos 3kg", "Petisco"},
    {"Coleira", "Brinquedo", "Caminha"},
    {"Shampoo", "Escova", "Tapete higienico"}
};
float precosProdutos[3][3] = {
    {120.00f, 65.00f, 12.50f},
    {25.00f, 18.00f, 90.00f},
    {22.00f, 15.00f, 35.00f}
};

/* ---------- LEITURA DE DADOS ---------- */

/* Le uma linha com getchar() ate o ENTER e guarda em "destino".
   O que passar do tamanho e descartado. */
void lerTexto(char destino[], int tamanho)
{
    int c, i = 0;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (i < tamanho - 1)
        {
            destino[i++] = (char)c;
        }
    }
    destino[i] = '\0';
}

/* Le um numero. Se nao comecar com digito, retorna -1 (opcao invalida) */
int lerInteiro(void)
{
    char buffer[20];

    lerTexto(buffer, 20);
    if (buffer[0] < '0' || buffer[0] > '9')
    {
        return -1;
    }
    return atoi(buffer);
}

/* ---------- MENU GENERICO ----------
   Mostra "titulo" e as n opcoes de "itens" (numeradas de 1 a n), mais a
   opcao 0 com o texto "zero". Repete (do-while) ate o usuario digitar
   uma opcao valida e retorna o numero escolhido. */
int menu(char titulo[], char itens[][TAM_TEXTO], int n, char zero[])
{
    int i, opcao;

    do
    {
        printf("\n----- %s -----\n", titulo);
        for (i = 0; i < n; i++)
        {
            printf("%d - %s\n", i + 1, itens[i]);
        }
        printf("0 - %s\n", zero);
        printf("Escolha uma opcao: ");
        opcao = lerInteiro();
        if (opcao < 0 || opcao > n)
        {
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao < 0 || opcao > n);

    return opcao;
}

/* ---------- LOGIN ---------- */

/* Ate 3 tentativas. Retorna 1 se acertou e 0 se as tentativas acabaram */
int login(void)
{
    char usuario[TAM_TEXTO], senha[TAM_TEXTO];
    int tentativa;

    printf("===== PETSHOP AMIGO FIEL - LOGIN =====\n");
    for (tentativa = 1; tentativa <= 3; tentativa++)
    {
        printf("Usuario: ");
        lerTexto(usuario, TAM_TEXTO);
        printf("Senha: ");
        lerTexto(senha, TAM_TEXTO);

        if (strcmp(usuario, USUARIO) == 0 && strcmp(senha, SENHA) == 0)
        {
            strcpy(funcionario, usuario);
            return 1;
        }
        printf("Usuario ou senha incorretos (%d de 3).\n\n", tentativa);
    }
    printf("Tentativas esgotadas. Encerrando o programa.\n");
    return 0;
}

/* ---------- ETAPA 3: CADASTROS ---------- */

void cadastrarCliente(void)
{
    printf("Nome do cliente: ");
    lerTexto(clienteNome, TAM_TEXTO);
    printf("Telefone: ");
    lerTexto(clienteTelefone, TAM_TEXTO);

    clienteCadastrado = 1;
    petCadastrado = 0; /* pet antigo pertencia ao cliente anterior */
    printf("Cliente cadastrado!\n");
}

/* O pet so pode ser cadastrado depois do cliente */
void cadastrarPet(void)
{
    if (!clienteCadastrado)
    {
        printf("Cadastre um cliente antes do pet.\n");
        return;
    }

    printf("Nome do pet: ");
    lerTexto(petNome, TAM_TEXTO);

    do
    {
        printf("Especie (cao ou gato): ");
        lerTexto(petEspecie, TAM_TEXTO);
    } while (strcmp(petEspecie, "cao") != 0 && strcmp(petEspecie, "gato") != 0);

    printf("Raca: ");
    lerTexto(petRaca, TAM_TEXTO);

    do
    {
        printf("Porte (pequeno, medio ou grande): ");
        lerTexto(petPorte, TAM_TEXTO);

        if (strcmp(petPorte, "pequeno") == 0)
        {
            petPorteCodigo = 1;
        }
        else if (strcmp(petPorte, "medio") == 0)
        {
            petPorteCodigo = 2;
        }
        else if (strcmp(petPorte, "grande") == 0)
        {
            petPorteCodigo = 3;
        }
        else
        {
            petPorteCodigo = 0;
        }
    } while (petPorteCodigo == 0);

    petCadastrado = 1;
    printf("Pet cadastrado!\n");
}

void menuCadastros(void)
{
    int opcao;

    do
    {
        opcao = menu("CADASTROS", itensCadastros, 2, "Voltar");
        switch (opcao)
        {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                cadastrarPet();
                break;
        }
    } while (opcao != 0);
}

/* ---------- ETAPA 6 (parte 1): REGISTRO DOS ITENS ---------- */

/* Guarda um item nos vetores e avisa o usuario */
void registrarItem(char descricao[], int quantidade, float valor)
{
    if (totalItens >= MAX_ITENS)
    {
        printf("Limite de itens atingido!\n");
        return;
    }
    strcpy(itemDescricao[totalItens], descricao);
    itemQuantidade[totalItens] = quantidade;
    itemValor[totalItens] = valor;
    totalItens++;
    printf("Adicionado: %dx %s - R$ %.2f\n", quantidade, descricao, valor);
}

/* ---------- ETAPA 4: SERVICOS ----------
   Cada servico e uma funcao que recebe a opcao e retorna o valor */

float banho(int porte)
{
    switch (porte)
    {
        case 1: return 40.00f;
        case 2: return 60.00f;
        case 3: return 80.00f;
    }
    return 0.0f;
}

float tosa(int opcao)
{
    switch (opcao)
    {
        case 1: return 45.00f;
        case 2: return 70.00f;
        case 3: return 90.00f;
    }
    return 0.0f;
}

float veterinaria(int opcao)
{
    switch (opcao)
    {
        case 1: return 120.00f;
        case 2: return 80.00f;
        case 3: return 150.00f;
    }
    return 0.0f;
}

/* Servicos so podem ser contratados depois do cadastro do pet */
void menuServicos(void)
{
    int opcao, sub;
    char descricao[TAM_TEXTO];

    if (!petCadastrado)
    {
        printf("Cadastre o cliente e o pet antes dos servicos.\n");
        return;
    }

    do
    {
        opcao = menu("SERVICOS", itensServicos, 3, "Voltar");
        switch (opcao)
        {
            case 1:
                sprintf(descricao, "Banho (porte %.20s)", petPorte);
                registrarItem(descricao, 1, banho(petPorteCodigo));
                break;
            case 2:
                sub = menu("TOSA", itensTosa, 3, "Voltar");
                if (sub > 0)
                {
                    registrarItem(itensTosa[sub - 1], 1, tosa(sub));
                }
                break;
            case 3:
                sub = menu("VETERINARIA", itensVet, 3, "Voltar");
                if (sub > 0)
                {
                    registrarItem(itensVet[sub - 1], 1, veterinaria(sub));
                }
                break;
        }
    } while (opcao != 0);
}

/* ---------- ETAPA 5: PRODUTOS ---------- */

/* Mostra os produtos da categoria "cat", pede produto e quantidade
   e registra o item com valor = preco x quantidade */
void escolherProduto(int cat)
{
    char lista[3][TAM_TEXTO];
    int i, produto, quantidade;

    for (i = 0; i < 3; i++)
    {
        sprintf(lista[i], "%.30s (R$ %.2f)", nomesProdutos[cat][i], precosProdutos[cat][i]);
    }

    produto = menu(categorias[cat], lista, 3, "Voltar");
    if (produto == 0)
    {
        return;
    }

    printf("Quantidade: ");
    quantidade = lerInteiro();
    if (quantidade < 1)
    {
        printf("Quantidade invalida!\n");
        return;
    }

    registrarItem(nomesProdutos[cat][produto - 1], quantidade, precosProdutos[cat][produto - 1] * quantidade);
}

void menuProdutos(void)
{
    int opcao;

    do
    {
        opcao = menu("PRODUTOS", categorias, 3, "Voltar");
        switch (opcao)
        {
            case 1:
                escolherProduto(0);
                break;
            case 2:
                escolherProduto(1);
                break;
            case 3:
                escolherProduto(2);
                break;
        }
    } while (opcao != 0);
}

/* ---------- ETAPA 6 (parte 2): COMPROVANTE ---------- */

void comprovante(void)
{
    int i;
    float total = 0.0f;

    if (!petCadastrado)
    {
        printf("Cadastre o cliente e o pet antes do comprovante.\n");
        return;
    }

    printf("\n=========== COMPROVANTE ===========\n");
    printf("Funcionario: %s\n", funcionario);
    printf("Cliente: %s (Tel: %s)\n", clienteNome, clienteTelefone);
    printf("Pet: %s - %s - %s - porte %s\n", petNome, petEspecie, petRaca, petPorte);
    printf("-----------------------------------\n");

    for (i = 0; i < totalItens; i++)
    {
        printf("%d) %s | Qtd: %d | R$ %.2f\n", i + 1, itemDescricao[i], itemQuantidade[i], itemValor[i]);
        total += itemValor[i];
    }

    printf("-----------------------------------\n");
    printf("VALOR TOTAL: R$ %.2f\n", total);
    printf("===================================\n");
}

/* ---------- ETAPA 2: MENU PRINCIPAL ---------- */

int main(void)
{
    int opcao;

    if (!login())
    {
        return 0;
    }

    do
    {
        opcao = menu("PETSHOP AMIGO FIEL", itensPrincipal, 4, "Sair");
        switch (opcao)
        {
            case 1:
                menuCadastros();
                break;
            case 2:
                menuServicos();
                break;
            case 3:
                menuProdutos();
                break;
            case 4:
                comprovante();
                break;
        }
    } while (opcao != 0);

    printf("Encerrando o sistema. Ate logo!\n");
    return 0;
}