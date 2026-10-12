#include <stdio.h>
#include <ctype.h>

int main() {
    char nome[50];
    char sexo;
    char estado_civil;
    int tempo_casamento;

    printf("Digite o nome: ");
    scanf(" %[^\n]", nome);

    printf("Digite o sexo (F - Feminino / M - Masculino): ");
    scanf(" %c", &sexo);
    sexo = toupper(sexo);

    printf("Digite o estado civil (C - Casado(a) / S - Solteiro(a) / D - Divorciado(a) / V - Viúvo(a)): ");
    scanf(" %c", &estado_civil);
    estado_civil = toupper(estado_civil);

    if (sexo == 'F' && estado_civil == 'C') {
        printf("Digite o tempo de casamento (em anos): ");
        scanf("%d", &tempo_casamento);

        printf("\n--- Dados Cadastrados ---\n");
        printf("Nome: %s\n", nome);
        printf("Sexo: %c\n", sexo);
        printf("Estado Civil: Casada\n");
        printf("Tempo de Casamento: %d ano(s)\n", tempo_casamento);
    } 

    else {
        printf("\n--- Dados Cadastrados ---\n");
        printf("Nome: %s\n", nome);
        printf("Sexo: %c\n", sexo);
        printf("Estado Civil: %c\n", estado_civil);
    }

    return 0;
}