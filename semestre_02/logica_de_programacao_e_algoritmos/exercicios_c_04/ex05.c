#include <stdio.h>

#define PI 3.1414592

double volumeEsfera(double raio){
    return (4.0 / 3.0) * PI * raio * raio * raio;
}

int main(void){
    double r;
    printf("Digite o raio da esfera: ");
    scanf("%lf", &r);
    printf("Volume da esfera: %.4f\n", volumeEsfera(r));
    return 0;
}
