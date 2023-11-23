#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int verificaDataValida(int dia, int mes, int ano){
    int diasMes;
    diasMes = numeroDiasMes(mes, ano);
    if(dia < 1 || dia > diasMes){
        return 0;
    }
    if(mes < 1 || mes > 12){
        return 0;
    }
    return 1;
}

void imprimeData(int dia, int mes, int ano){
    printf("%02d/%02d/%04d", dia, mes, ano);
}

void imprimeMesExtenso(int mes){
    if(mes == 1){
        printf("Janeiro");
    }
    else if(mes == 2){
        printf("Fevereiro");
    }
    else if(mes == 3){
        printf("Marco");
    }
    else if(mes == 4){
        printf("Abril");
    }
    else if(mes == 5){
        printf("Maio");
    }
    else if(mes == 6){
        printf("Junho");
    }
    else if(mes == 7){
        printf("Julho");
    }
    else if(mes == 8){
        printf("Agosto");
    }
    else if(mes == 9){
        printf("Setembro");
    }
    else if(mes == 10){
        printf("Outubro");
    }
    else if(mes == 11){
        printf("Novembro");
    }
    else if(mes == 12){
        printf("Dezembro");
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" %04d\n", ano);
}

int verificaBissexto(int ano){
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        return 1;
    }
    return 0;
}

int numeroDiasMes(int mes, int ano){
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        return 31;
    }
    else if(mes == 2){
        if (verificaBissexto(ano)){
            return 29;
        }
        else {
            return 28;
        }
    }
    return 30;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if (ano1 > ano2){
        return 1;
    }
    else if (ano1 < ano2){
        return -1;
    }
    else {
        if (mes1 > mes2){
            return 1;
        }
        else if (mes1 < mes2){
            return -1;
        }
        else {
            if (dia1 > dia2){
                return 1;
            }
            else if (dia1 < dia2){
                return -1;
            }
            else {
                return 0;
            }
        }
    }
}

int calculaDiasAteMes(int mes, int ano){
    int diasAteMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dias = 0;

    if (verificaBissexto(ano)) {
        diasAteMes[2] = 29;
    }
    for (int i = 1; i < mes; i++) {
        dias += diasAteMes[i];
    }

    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int total1 = 0;
    int total2 = 0;
    int diferenca;
   
    for (int i = 0; i <= ano1; i++)
    {
        if (verificaBissexto(ano1))
        {
            total1 = total1 + 366;
        }
        else {
            total1 = total1 + 365;
        }
    }

    total1 = total1 + calculaDiasAteMes(mes1, ano1);
    total1 = total1 + dia1;
    
    for (int i = 0; i <= ano2; i++)
    {
        if (verificaBissexto(ano2))
        {
            total2 = total2 + 366;
        }
        else {
            total2 = total2 + 365;
        }
    }

    total2 = total2 + calculaDiasAteMes(mes2, ano2);
    total2 = total2 + dia2;

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1)
    {
        diferenca = total1 - total2;
    }
    else if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1)
    {
        diferenca = total2 - total1;
    }
    else {
        return 0;
    }
}

void imprimeProximaData(int dia, int mes, int ano){
    if (dia < numeroDiasMes(mes, ano))
    {
        dia++;
    }
    else {
        if (mes < 12)
        {
            mes++;
            dia = 1;
        }
        else {
            ano++;
            mes = 1;
            dia = 1;
        }
    }
    imprimeData(dia, mes, ano);
}