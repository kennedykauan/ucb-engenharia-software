#include <stdio.h>

#define N 10

void trocar(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

void realizarTrocas(int a[N][N]){
    int j, i;

    for (j = 0; j < N; j++)
        trocar(&a[1][j], &a[7][j]);

    for (i = 0; i < N; i++)
        trocar(&a[i][3], &a[i][9]);

    for (i = 0; i < N; i++)
        trocar(&a[i][i], &a[i][N - 1 - i]);

    for (i = 0; i < N; i++)
        trocar(&a[4][i], &a[i][9]);
}

void imprimir(int a[N][N]){
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

int main(void){
    int a[N][N], i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            a[i][j] = i * N + j + 1;

    printf("Matriz original:\n");
    imprimir(a);

    realizarTrocas(a);

    printf("\nMatriz alterada:\n");
    imprimir(a);
    return 0;
}
