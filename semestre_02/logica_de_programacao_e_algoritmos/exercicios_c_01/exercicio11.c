#include <stdio.h>

// biblioteca para funções matemáticas usada para raiz quadrada e raiz cúbica no código.
#include <math.h>

int main() {
    int numero, quadrado, cubo;
    double raiz_quadrada, raiz_cubica;

    printf("Digite um numero positivo e maior que zero: ");
    scanf("%d", &numero);

    quadrado = numero * numero;
    cubo = numero * numero * numero;

    // função que calcula a raiz quadradado numero
    raiz_quadrada = sqrt(numero);

    // função que calcula a raiz cubica do numero
    raiz_cubica = cbrt(numero);

    printf("a) Numero ao quadrado: %d\n", quadrado);
    printf("b) Numero ao cubo: %d\n", cubo);
    printf("c) Raiz quadrada: %.2lf\n", raiz_quadrada);
    printf("d) Raiz cubica: %.2lf\n", raiz_cubica);

    return 0;
}