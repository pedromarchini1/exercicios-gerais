#include "ponto.h"
#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    float x, y, r;
    float x2, y2;
    tCirculo circulo;
    tPonto ponto;
    scanf("%f %f %f %f %f", &x, &y, &r, &x2, &y2);

    circulo = Circulo_Cria(x, y, r);
    ponto = Pto_Cria(x2, y2);
    int resposta = (Circulo_Interior(circulo, ponto));

    printf("%d", resposta);
    Circulo_Apaga(circulo);
    Pto_Apaga(ponto);
    return 0;
}