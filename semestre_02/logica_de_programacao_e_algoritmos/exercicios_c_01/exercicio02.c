#include <stdio.h>

int main()
{
    // Declaração de variáveis
    float n1, n2, n3, n4, media;
    
    printf("Digite o valor da primeira nota: ");
    scanf("%f", &n1);
    
    printf("Digite o valor da segunda nota: ");
    scanf("%f", &n2);
    
    printf("Digite o valor da terceira nota: ");
    scanf("%f", &n3);
    
    media = (n1+n2+n3)/3;
    
    printf("A média das notas digitadas é %f", media);

    return 0;
    
}
