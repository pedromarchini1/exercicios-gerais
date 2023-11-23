#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main(){
    int dia, mes, ano;
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if (!verificaDataValida(dia, mes, ano))
    {
        printf("A data informada eh invalida\n");
        return 0;
    }
    
    printf("Data informada: ");
    imprimeDataExtenso(dia, mes, ano);
    if (verificaBissexto(ano))
    {
        printf("O ano informado eh bissexto\n");
    }
    else {
        printf("O ano informado nao eh bissexto\n");
    }

    int DiasMes = numeroDiasMes(mes, ano);
    printf("O mes informado possui %d dias\n", DiasMes);
    printf("A data seguinte eh: ");
    imprimeProximaData(dia, mes, ano);
    printf("\n");
    return 0;
}