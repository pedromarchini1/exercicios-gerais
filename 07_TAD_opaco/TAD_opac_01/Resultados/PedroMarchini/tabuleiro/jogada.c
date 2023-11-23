#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>

struct Jogada{
    int x;
    int y;
};

tJogada* CriaJogada(){
    tJogada* jogada = malloc(sizeof(tJogada));

    if (jogada == NULL)
    {
        printf("Erro na alocacao dinamica\n");
        exit(1);
    }

    jogada->x = 0;
    jogada->y = 0;
    
    return jogada;
}

void DestroiJogada(tJogada* jogada){
    free(jogada);
}

void LeJogada(tJogada* jogada){
    printf("Digite uma posicao (x e y):\n");
    scanf("%d %d", &jogada->x, &jogada->y);
}

int ObtemJogadaX(tJogada* jogada){
    return jogada->x;
}

int ObtemJogadaY(tJogada* jogada){
    return jogada->y;
}

int FoiJogadaBemSucedida(tJogada* jogada){
    if (jogada->x == (int)jogada->x && jogada->y == (int)jogada->y)
    {
        return 1;
    }
    return 0;
}