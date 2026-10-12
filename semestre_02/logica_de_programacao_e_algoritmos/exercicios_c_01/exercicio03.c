#include<stdio.h>

int main(){
    float n1, n2, n3, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &n1);

    printf("Digite a segunda nota: ");
    scanf("%f", &n2);
    
    printf("Digite a terceira nota: ");
    scanf("%f", &n3);

    n2 = n2 * 2;
    n3 = n3 * 3;

    media = (n1 + n2 + n3) / 3;

    printf("A media das notas eh: %.2f\n", media);

    return 0;
}