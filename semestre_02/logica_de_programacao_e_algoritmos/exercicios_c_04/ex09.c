#include <stdio.h>

#define LINHAS 61
#define COLUNAS 10

void somarColunas(int m[LINHAS][COLUNAS]){
    int i, j;
    for (j = 0; j < COLUNAS; j++) {
        m[LINHAS - 1][j] = 0;
        for (i = 0; i < LINHAS - 1; i++)
            m[LINHAS - 1][j] += m[i][j];
    }
}

int main(void){
    int m[LINHAS][COLUNAS], i, j;

    for (i = 0; i < LINHAS - 1; i++)
        for (j = 0; j < COLUNAS; j++)
            m[i][j] = i + j;

    somarColunas(m);

    printf("Soma de cada coluna:\n");
    for (j = 0; j < COLUNAS; j++)
        printf("Coluna %d: %d\n", j + 1, m[LINHAS - 1][j]);
    return 0;
}
