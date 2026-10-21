#include <stdio.h>

double maior(double a, double b){
    return a > b ? a : b;
}

int main(void){
    double x, y;
    printf("Digite o primeiro numero: ");
    scanf("%lf", &x);
    printf("Digite o segundo numero: ");
    scanf("%lf", &y);
    printf("O maior e: %.2f\n", maior(x, y));
    return 0;
}
