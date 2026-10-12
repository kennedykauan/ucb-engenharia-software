#include <stdio.h>

int main() {
    int valores[6];
    int i, n;

    i = 0;
    while (i < 6) {
        printf("Digite o valor par %d: ", i + 1);
        scanf("%d", &n);
        if (n % 2 == 0) {
            valores[i] = n;
            i++;
        } else {
            printf("Valor invalido! Digite um numero par.\n");
        }
    }

    printf("\nValores na ordem inversa:\n");
    for (i = 5; i >= 0; i--) {
        printf("%d\n", valores[i]);
    }

    return 0;
}