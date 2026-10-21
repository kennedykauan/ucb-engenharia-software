#include <stdio.h>
#include <time.h>

int bissexto(int ano){
    return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}

int diasNoMes(int mes, int ano){
    int dm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && bissexto(ano))
        return 29;
    return dm[mes - 1];
}

void calcularIdade(int dia, int mes, int ano){
    time_t agora = time(NULL);
    struct tm hoje = *localtime(&agora);
    struct tm nasc = {0};
    int dh = hoje.tm_mday;
    int mh = hoje.tm_mon + 1;
    int ah = hoje.tm_year + 1900;
    int anos = ah - ano;
    int meses = mh - mes;
    int dias = dh - dia;
    long totalDias;

    if (dias < 0) {
        int mesAnterior = mh == 1 ? 12 : mh - 1;
        int anoAnterior = mh == 1 ? ah - 1 : ah;
        meses--;
        dias += diasNoMes(mesAnterior, anoAnterior);
    }
    if (meses < 0) {
        anos--;
        meses += 12;
    }

    nasc.tm_mday = dia;
    nasc.tm_mon = mes - 1;
    nasc.tm_year = ano - 1900;
    nasc.tm_hour = 12;
    nasc.tm_isdst = -1;
    hoje.tm_hour = 12;
    hoje.tm_min = 0;
    hoje.tm_sec = 0;
    hoje.tm_isdst = -1;
    totalDias = (long)(difftime(mktime(&hoje), mktime(&nasc)) / 86400.0 + 0.5);

    printf("Idade: %d anos, %d meses e %d dias\n", anos, meses, dias);
    printf("Total de dias vividos: %ld\n", totalDias);
}

int main(void){
    int d, m, a;
    printf("Digite a data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &d, &m, &a);
    calcularIdade(d, m, a);
    return 0;
}
