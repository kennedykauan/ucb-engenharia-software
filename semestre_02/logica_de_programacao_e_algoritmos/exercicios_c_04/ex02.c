#include <stdio.h>

void mostrarMes(int numero){
    const char *meses[] = {"janeiro", "fevereiro", "marco", "abril", "maio", "junho",
                           "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (numero < 1 || numero > 12) {
        printf("Numero invalido. Digite um valor entre 1 e 12.\n");
        return;
    }
    printf("%s - %d dias\n", meses[numero - 1], dias[numero - 1]);
}

int main(void){
    int n;
    printf("Digite um numero de 1 a 12: ");
    scanf("%d", &n);
    mostrarMes(n);
    return 0;
}
