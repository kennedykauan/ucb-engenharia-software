#include <stdio.h>

int main() {
    int valores[6];
    int i;

    for (i = 0; i < 6; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valores[i]);
    }

    printf("\nValores na ordem inversa:\n");
    for (i = 5; i >= 0; i--) {
        printf("%d\n", valores[i]);
    }

    return 0;
}