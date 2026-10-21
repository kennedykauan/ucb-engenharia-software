#include <stdio.h>

#define PI 3.1414592

double volumeCilindro(double altura, double raio){
    return PI * raio * raio * altura;
}

int main(void){
    double h, r;
    printf("Digite a altura do cilindro: ");
    scanf("%lf", &h);
    printf("Digite o raio do cilindro: ");
    scanf("%lf", &r);
    printf("Volume do cilindro: %.4f\n", volumeCilindro(h, r));
    return 0;
}
