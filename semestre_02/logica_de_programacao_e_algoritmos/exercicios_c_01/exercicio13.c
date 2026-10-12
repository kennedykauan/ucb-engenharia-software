#include <stdio.h>

int main() {
    float pes, polegadas, jardas, milhas;

    printf("Digite a medida em pes: ");
    scanf("%f", &pes);

    // conversão
    polegadas = pes * 12.0;
    jardas = pes / 3.0;
    milhas = jardas / 1760.0;
    
    printf("Polegadas: %.2f\n", polegadas);
    printf("Jardas: %.2f\n", jardas);
    printf("Milhas: %.6f\n", milhas);
    
    return 0;
}