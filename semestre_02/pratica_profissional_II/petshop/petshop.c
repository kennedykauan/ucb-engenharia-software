#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 100
#define TAM_TEXTO 50
#define USUARIO "admin"
#define SENHA "1234"

// Dados do atendimento
char funcionario[TAM_TEXTO];
char clienteNome[TAM_TEXTO], clienteTelefone[TAM_TEXTO];
char petNome[TAM_TEXTO], petEspecie[20], petRaca[TAM_TEXTO], petPorte[20];
int clienteCadastrado = 0, petCadastrado = 0;
int petPorteCodigo = 0; // 1 = pequeno, 2 = medio, 3 = grande

// Vetores paralelos para o comprovante
char itemDescricao[MAX_ITENS][TAM_TEXTO];
int itemQuantidade[MAX_ITENS];
float itemValor[MAX_ITENS];
int totalItens = 0;

// Vetores de produtos (0 = Alimentos, 1 = Acessorios, 2 = Higiene)
char categorias[3][TAM_TEXTO] = {"ALIMENTOS", "ACESSORIOS", "HIGIENE"};
char nomesProdutos[3][3][TAM_TEXTO] = {
    {"Racao cao 10kg", "Racao gato 3kg", "Petisco"},
    {"Coleira", "Brinquedo", "Caminha"},
    {"Shampoo", "Escova", "Tapete higienico"}
};
float precosProdutos[3][3] = {
    {120.00, 65.00, 15.00},
    {25.00, 18.00, 90.00},
    {22.00, 15.00, 35.00}
};

void lerTexto(char destino[], int tamanho) {
    int c, i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < tamanho - 1) {
            destino[i] = c;
            i++;
        }
    }
    destino[i] = '\0';
}

int lerInteiro() {
    char buffer[20];
    lerTexto(buffer, 20);
    if (buffer[0] < '0' || buffer[0] > '9') {
        return -1;
    }
    return atoi(buffer);
}

// Login do funcionario ate 3 tentativas
int login() {
    char usuario[TAM_TEXTO], senha[TAM_TEXTO];
    int tentativa;

    printf("PETSHOP Kennedy da silva - LOGIN\n");
    for (tentativa = 1; tentativa <= 3; tentativa++) {
        printf("Usuario: ");
        lerTexto(usuario, TAM_TEXTO);
        printf("Senha: ");
        lerTexto(senha, TAM_TEXTO);

        if (strcmp(usuario, USUARIO) == 0 && strcmp(senha, SENHA) == 0) {
            strcpy(funcionario, usuario);
            printf("Login realizado com sucesso!\n");
            return 1;
        }
        printf("Usuario ou senha incorretos (%d de 3).\n\n", tentativa);
    }
    printf("Tentativas esgotadas. Encerrando o programa.\n");
    return 0;
}

void registrarItem(char descricao[], int quantidade, float valor) {
    if (totalItens >= MAX_ITENS) {
        printf("Limite de itens atingido!\n");
        return;
    }
    strcpy(itemDescricao[totalItens], descricao);
    itemQuantidade[totalItens] = quantidade;
    itemValor[totalItens] = valor;
    totalItens++;
    printf("Valor: R$ %.2f (Adicionado: %dx %s)\n", valor, quantidade, descricao);
}

// Cadastros
void cadastrarCliente() {
    printf("\nNome do cliente: ");
    lerTexto(clienteNome, TAM_TEXTO);
    printf("Telefone: ");
    lerTexto(clienteTelefone, TAM_TEXTO);

    clienteCadastrado = 1;
    petCadastrado = 0;
    printf("Cliente cadastrado!\n");
}

void cadastrarPet() {
    if (!clienteCadastrado) {
        printf("\nCadastre um cliente antes do pet.\n");
        return;
    }

    printf("\nNome do pet: ");
    lerTexto(petNome, TAM_TEXTO);

    do {
        printf("Especie (cao ou gato): ");
        lerTexto(petEspecie, 20);
        if (strcmp(petEspecie, "cao") != 0 && strcmp(petEspecie, "gato") != 0) {
            printf("Especie invalida! Digite cao ou gato.\n");
        }
    } while (strcmp(petEspecie, "cao") != 0 && strcmp(petEspecie, "gato") != 0);

    printf("Raca: ");
    lerTexto(petRaca, TAM_TEXTO);

    do {
        printf("Porte (pequeno, medio ou grande): ");
        lerTexto(petPorte, 20);

        if (strcmp(petPorte, "pequeno") == 0) {
            petPorteCodigo = 1;
        } else if (strcmp(petPorte, "medio") == 0) {
            petPorteCodigo = 2;
        } else if (strcmp(petPorte, "grande") == 0) {
            petPorteCodigo = 3;
        } else {
            petPorteCodigo = 0;
            printf("Porte invalido! Digite pequeno, medio ou grande.\n");
        }
    } while (petPorteCodigo == 0);

    petCadastrado = 1;
    printf("Pet cadastrado!\n");
}

void menuCadastros() {
    int opcao;
    do {
        printf("\n--------- CADASTROS ----------\n");
        printf("  1 - Cadastrar cliente\n");
        printf("  2 - Cadastrar pet\n");
        printf("  0 - Voltar\n");
        printf("Escolha uma opcao: ");
        opcao = lerInteiro();

        switch (opcao) {
            case 1: cadastrarCliente(); break;
            case 2: cadastrarPet(); break;
            case 0: break;
            default: printf("Opcao invalida! Tente novamente.\n"); break;
        }
    } while (opcao != 0);
}

// Servicos
float banho(int porte) {
    switch (porte) {
        case 1: return 40.00;
        case 2: return 60.00;
        case 3: return 80.00;
        default: return 0.00;
    }
}

float tosa(int opcao) {
    switch (opcao) {
        case 1: return 45.00;
        case 2: return 70.00;
        case 3: return 90.00;
        default: return 0.00;
    }
}

float veterinaria(int opcao) {
    switch (opcao) {
        case 1: return 120.00;
        case 2: return 80.00;
        case 3: return 150.00;
        default: return 0.00;
    }
}

void menuServicos() {
    int opcao, sub;
    char descricao[TAM_TEXTO];

    if (!petCadastrado) {
        printf("\nCadastre o cliente e o pet antes dos servicos.\n");
        return;
    }

    do {
        printf("\n---------- SERVICOS ----------\n");
        printf("  1 - Banho\n");
        printf("  2 - Tosa\n");
        printf("  3 - Veterinaria\n");
        printf("  0 - Voltar\n");
        printf("Escolha uma opcao: ");
        opcao = lerInteiro();

        switch (opcao) {
            case 1:
                sprintf(descricao, "Banho (porte %s)", petPorte);
                registrarItem(descricao, 1, banho(petPorteCodigo));
                break;
            case 2:
                do {
                    printf("\n------------ TOSA ------------\n");
                    printf("  1 - Tosa higienica   R$ 45,00\n");
                    printf("  2 - Tosa completa    R$ 70,00\n");
                    printf("  3 - Tosa na tesoura  R$ 90,00\n");
                    printf("  0 - Voltar\n");
                    printf("Escolha uma opcao: ");
                    sub = lerInteiro();

                    switch (sub) {
                        case 1: registrarItem("Tosa higienica", 1, tosa(1)); break;
                        case 2: registrarItem("Tosa completa", 1, tosa(2)); break;
                        case 3: registrarItem("Tosa na tesoura", 1, tosa(3)); break;
                        case 0: break;
                        default: printf("Opcao invalida! Tente novamente.\n"); break;
                    }
                } while (sub != 0);
                break;
            case 3:
                do {
                    printf("\n-------- VETERINARIA ---------\n");
                    printf("  1 - Consulta         R$ 120,00\n");
                    printf("  2 - Vacina           R$  80,00\n");
                    printf("  3 - Exame            R$ 150,00\n");
                    printf("  0 - Voltar\n");
                    printf("Escolha uma opcao: ");
                    sub = lerInteiro();

                    switch (sub) {
                        case 1: registrarItem("Consulta", 1, veterinaria(1)); break;
                        case 2: registrarItem("Vacina", 1, veterinaria(2)); break;
                        case 3: registrarItem("Exame", 1, veterinaria(3)); break;
                        case 0: break;
                        default: printf("Opcao invalida! Tente novamente.\n"); break;
                    }
                } while (sub != 0);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}

// Produtos
void escolherProduto(int cat) {
    int i, produto, quantidade;
    float valor;

    do {
        printf("\n--------- %s ----------\n", categorias[cat]);
        for (i = 0; i < 3; i++) {
            printf("  %d - %s - R$ %.2f\n", i + 1, nomesProdutos[cat][i], precosProdutos[cat][i]);
        }
        printf("  0 - Voltar\n");
        printf("Produto: ");
        produto = lerInteiro();

        switch (produto) {
            case 1:
            case 2:
            case 3:
                printf("Quantidade: ");
                quantidade = lerInteiro();
                if (quantidade > 0) {
                    valor = precosProdutos[cat][produto - 1] * quantidade;
                    registrarItem(nomesProdutos[cat][produto - 1], quantidade, valor);
                } else {
                    printf("Quantidade invalida!\n");
                }
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (produto != 0);
}

void menuProdutos() {
    int opcao;
    do {
        printf("\n---------- PRODUTOS ----------\n");
        printf("  1 - Alimentos\n");
        printf("  2 - Acessorios\n");
        printf("  3 - Higiene\n");
        printf("  0 - Voltar\n");
        printf("Escolha uma opcao: ");
        opcao = lerInteiro();

        switch (opcao) {
            case 1: escolherProduto(0); break;
            case 2: escolherProduto(1); break;
            case 3: escolherProduto(2); break;
            case 0: break;
            default: printf("Opcao invalida! Tente novamente.\n"); break;
        }
    } while (opcao != 0);
}

// Comprovante final
void comprovante() {
    int i;
    float total = 0.0;

    if (!petCadastrado) {
        printf("\nCadastre o cliente e o pet antes do comprovante.\n");
        return;
    }

    printf("\n=========== COMPROVANTE ===========\n");
    printf("Funcionario: %s\n", funcionario);
    printf("Cliente: %s (Tel: %s)\n", clienteNome, clienteTelefone);
    printf("Pet: %s - %s - %s - porte %s\n", petNome, petEspecie, petRaca, petPorte);
    printf("-----------------------------------\n");

    if (totalItens == 0) {
        printf("Nenhum item registrado.\n");
    } else {
        for (i = 0; i < totalItens; i++) {
            printf("%d) %s | Qtd: %d | R$ %.2f\n", i + 1, itemDescricao[i], itemQuantidade[i], itemValor[i]);
            total += itemValor[i];
        }
    }

    printf("-----------------------------------\n");
    printf("VALOR TOTAL: R$ %.2f\n", total);
    printf("===================================\n");
}

// Menu principal
int main() {
    int opcao;

    if (!login()) {
        return 0;
    }

    do {
        printf("\n==============================\n");
        printf("     PETSHOP AMIGO FIEL\n");
        printf("==============================\n");
        printf("  1 - Cadastros\n");
        printf("  2 - Servicos\n");
        printf("  3 - Produtos\n");
        printf("  4 - Comprovante final\n");
        printf("  0 - Sair\n");
        printf("==============================\n");
        printf("Escolha uma opcao: ");
        opcao = lerInteiro();

        switch (opcao) {
            case 1: menuCadastros(); break;
            case 2: menuServicos(); break;
            case 3: menuProdutos(); break;
            case 4: comprovante(); break;
            case 0: printf("Encerrando o sistema. Ate logo!\n"); break;
            default: printf("Opcao invalida! Tente novamente.\n"); break;
        }
    } while (opcao != 0);

    return 0;
}
