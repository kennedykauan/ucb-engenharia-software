#include <stdio.h>

int main() {
    int ano_nasc, ano_atual, idade, idade_2050;
    
    printf("Digite o ano de nascimento e o ano atual: ");
    scanf("%i %i", &ano_nasc, &ano_atual);
    
    idade = ano_atual - ano_nasc;
    idade_2050 = 2050 - ano_nasc;
    
    printf("Idade atual: %i anos\n", idade);
    printf("Idade em 2050: %i anos\n", idade_2050);
    return 0;
}
