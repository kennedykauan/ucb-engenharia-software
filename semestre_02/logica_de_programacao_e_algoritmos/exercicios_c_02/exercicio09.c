#include <stdio.h>
#include <ctype.h>

int main() {
    float altura, peso_ideal;
    char sexo;

    printf("Digite a altura (em metros, ex: 1.75): ");
    scanf("%f", &altura);

    printf("Digite o sexo (M - Masculino / F - Feminino): ");
    scanf(" %c", &sexo);
    sexo = toupper(sexo);

    if (sexo == 'M') {
        peso_ideal = (72.7 * altura) - 58;
        printf("\nPeso ideal para homens: %.2f kg\n", peso_ideal);
    } 
    
    else if (sexo == 'F') {
        peso_ideal = (62.1 * altura) - 44.7;
        printf("\nPeso ideal para mulheres: %.2f kg\n", peso_ideal);
    } 
    
    else {
        printf("\nOpcao de sexo invalida! Use M ou F.\n");
    }

    return 0;
}