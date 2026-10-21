#include <stdio.h>

#define N 500

void locacoesGratis(int a[], int gratis[]){
    int i;
    for (i = 0; i < N; i++)
        gratis[i] = a[i] / 15;
}

int main(void){
    int a[N], gratis[N], i;

    for (i = 0; i < N; i++)
        a[i] = (i * 7) % 60;

    locacoesGratis(a, gratis);

    for (i = 0; i < 10; i++)
        printf("Cliente %d: %d filmes -> %d locacoes gratis\n", i + 1, a[i], gratis[i]);
    return 0;
}
