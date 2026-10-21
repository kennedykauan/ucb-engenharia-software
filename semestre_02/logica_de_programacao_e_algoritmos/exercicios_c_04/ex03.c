#include <stdio.h>

double fahrenheitParaCelsius(double f){
    return (f - 32.0) * (5.0 / 9.0);
}

int main(void){
    double f;
    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%lf", &f);
    printf("Temperatura em Celsius: %.2f\n", fahrenheitParaCelsius(f));
    return 0;
}
