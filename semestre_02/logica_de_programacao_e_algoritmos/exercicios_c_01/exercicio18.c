#include <stdio.h>

int main() {
    float peso_saco_kg, racao_gato_g, peso_saco_g, consumo_5dias, restantec_g, restante_kg;
    
    printf("Digite o peso do saco de racao (em kg): ");
    scanf("%f", &peso_saco_kg);
    
    printf("Digite a quantidade de racao para cada gato (em gramas): ");
    scanf("%f", &racao_gato_g);
    
    // kg para gramas
    peso_saco_g = peso_saco_kg * 1000.0;
    
    // Consumo diário de 2 gatos por 5 dias
    consumo_5dias = (racao_gato_g * 2.0) * 5.0;
    restantec_g = peso_saco_g - consumo_5dias;
    restante_kg = restantec_g / 1000.0;
    
    printf("Restara no saco apos 5 dias: %.2f kg (ou %.2f g)\n", restante_kg, restantec_g);

    return 0;
}