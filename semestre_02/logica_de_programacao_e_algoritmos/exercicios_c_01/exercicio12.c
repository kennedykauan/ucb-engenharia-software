#include <stdio.h>
// biblioteca de funções matemáticas usada para potenciação.
#include <math.h> 

int main() {
    double num1, num2, resultado;

    printf("Digite dois numeros maiores que zero: ");
    scanf("%lf %lf", &num1, &num2);

    // função da biblioteca math que eleva o primeiro numero ao segundo numero
    resultado = pow(num1, num2);

    printf("%.2lf elevado a %.2lf eh: %.2lf\n", num1, num2, resultado);
    
    return 0;
}