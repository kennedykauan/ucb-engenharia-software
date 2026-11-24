#include <stdio.h>
#include <string.h>

#define QTD_ALUNOS 10

typedef struct {
    int matricula;
    char nome[100];
    float nota1;
    float nota2;
    float media;
} Aluno;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float calcularMedia(float n1, float n2) {
    return (n1 + n2) / 2.0f;
}

int main() {
    Aluno alunos[QTD_ALUNOS];
    float somaMedias = 0.0f, mediaGeral;
    int idxMaior = 0, idxMenor = 0, acimaMediaGeral = 0;

    printf("=== CADASTRO DE %d ALUNOS ===\n", QTD_ALUNOS);
    for (int i = 0; i < QTD_ALUNOS; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        limparBuffer();

        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);

        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

        alunos[i].media = calcularMedia(alunos[i].nota1, alunos[i].nota2);
        somaMedias += alunos[i].media;

        if (alunos[i].media > alunos[idxMaior].media) {
            idxMaior = i;
        }
        if (alunos[i].media < alunos[idxMenor].media) {
            idxMenor = i;
        }
    }

    mediaGeral = somaMedias / QTD_ALUNOS;

    printf("\n=== RESULTADOS DA TURMA ===\n");
    for (int i = 0; i < QTD_ALUNOS; i++) {
        const char *situacao = (alunos[i].media >= 6.0f) ? "APROVADO" : "REPROVADO";
        printf("Mat: %d | Nome: %-20s | Media: %.2f | Situacao: %s\n",
               alunos[i].matricula, alunos[i].nome, alunos[i].media, situacao);

        if (alunos[i].media > mediaGeral) {
            acimaMediaGeral++;
        }
    }

    printf("\nMaior media: %s (%.2f)\n", alunos[idxMaior].nome, alunos[idxMaior].media);
    printf("Menor media: %s (%.2f)\n", alunos[idxMenor].nome, alunos[idxMenor].media);
    printf("Media geral da turma: %.2f\n", mediaGeral);
    printf("Alunos acima da media geral: %d\n", acimaMediaGeral);

    return 0;
}