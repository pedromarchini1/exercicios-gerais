#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto{
    float x, y;
};

tPonto Pto_Cria (float x, float y){
    tPonto ponto = (tPonto) malloc (sizeof(struct ponto));

    if(ponto == NULL) {
        printf("Erro na alocacao dinamica\n");
        exit(1);
    }

    ponto->x = x;
    ponto->y = y;
    
    return ponto;
}

void Pto_Apaga (tPonto p){
    free(p);
}

float Pto_Acessa_y (tPonto p){
    return p->y;
}

float Pto_Acessa_x (tPonto p){
    return p->x;
}

void Pto_Atribui_x (tPonto p, float x){
    p->x = x;
}

void Pto_Atribui_y (tPonto p, float y){
    p->y = y;
}

float Pto_Distancia (tPonto p1, tPonto p2){
    float dist_x = p1->x - p2->x;
    float dist_y = p1->y - p2->y;
    float dist = sqrt((dist_x * dist_x) + (dist_y * dist_y));
    return dist;
}