#include <stdio.h>

int main() {
    float vel_maxima, vel_registrada, percentual_excedido;

    printf("Digite a velocidade maxima permitida na via (km/h): ");
    scanf("%f", &vel_maxima);

    printf("Digite a velocidade registrada do veiculo (km/h): ");
    scanf("%f", &vel_registrada);

    if (vel_registrada <= vel_maxima) {
        printf("\n--- RESULTADO DA FISCALIZACAO ---\n");
        printf("Limite da via: %.2f km/h\n", vel_maxima);
        printf("Velocidade registrada: %.2f km/h\n", vel_registrada);
        printf("Situacao: Nao houve infracao.\n");
    } 
    
    else {
        percentual_excedido = ((vel_registrada - vel_maxima) / vel_maxima) * 100.0;

        printf("\n--- RESULTADO DA FISCALIZACAO ---\n");
        printf("Limite da via: %.2f km/h\n", vel_maxima);
        printf("Velocidade registrada: %.2f km/h\n", vel_registrada);
        printf("Percentual excedido: %.2f%%\n", percentual_excedido);

        if (percentual_excedido <= 20.0) {
            printf("Classificacao da infracao: Media\n");
        } 
        
        else if (percentual_excedido <= 50.0) {
            printf("Classificacao da infracao: Grave\n");
        } 
        
        else {
            printf("Classificacao da infracao: Gravissima\n");
        }

        if (vel_registrada > 120.0) {
            printf("ALERTA: Velocidade extremamente elevada!\n");
        }
    }

    return 0;
}