#include <stdio.h>

int main() {
    float preco_fabrica, perc_dist, perc_imp, lucro_dist, valor_imp, preco_final;
    
    printf("Digite o preco de fabrica, %% de lucro e %% de impostos: ");
    scanf("%f %f %f", &preco_fabrica, &perc_dist, &perc_imp);
    
    lucro_dist = preco_fabrica * (perc_dist / 100.0);
    valor_imp = preco_fabrica * (perc_imp / 100.0);
    preco_final = preco_fabrica + lucro_dist + valor_imp;
    
    printf("Lucro do distribuidor: R$ %.2f\n", lucro_dist);
    printf("Valor dos impostos: R$ %.2f\n", valor_imp);
    printf("Preco final do veiculo: R$ %.2f\n", preco_final);

    return 0;
}