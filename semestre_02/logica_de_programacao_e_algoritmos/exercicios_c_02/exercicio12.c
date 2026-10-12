#include <stdio.h>

int main() {
    int id_aluno;
    float nota1, nota2, nota3, me, ma;
    char conceito;

    printf("Digite o numero de identificacao do aluno: ");
    scanf("%d", &id_aluno);

    printf("Digite a nota 1: ");
    scanf("%f", &nota1);

    printf("Digite a nota 2: ");
    scanf("%f", &nota2);

    printf("Digite a nota 3: ");
    scanf("%f", &nota3);

    printf("Digite a media dos exercicios (ME): ");
    scanf("%f", &me);

    ma = (nota1 + (nota2 * 2) + (nota3 * 3) + me) / 7.0;

    if (ma >= 90.0) {
        conceito = 'A';
    } 
    
    else if (ma >= 75.0) {
        conceito = 'B';
    } 
    
    else if (ma >= 60.0) {
        conceito = 'C';
    } 
    
    else if (ma >= 40.0) {
        conceito = 'D';
    } 
    
    else {
        conceito = 'E';
    }

    printf("\n--- RESULTADO DO ALUNO ---\n");
    printf("Numero de identificacao: %d\n", id_aluno);
    printf("Nota 1: %.2f\n", nota1);
    printf("Nota 2: %.2f\n", nota2);
    printf("Nota 3: %.2f\n", nota3);
    printf("Media dos exercicios (ME): %.2f\n", me);
    printf("Media de aproveitamento (MA): %.2f\n", ma);
    printf("Conceito obtido: %c\n", conceito);

    if (conceito == 'A' || conceito == 'B' || conceito == 'C') {
        printf("Situacao final: Aprovado\n");
    } 
    
    else {
        printf("Situacao final: Reprovado\n");
    }

    return 0;
}