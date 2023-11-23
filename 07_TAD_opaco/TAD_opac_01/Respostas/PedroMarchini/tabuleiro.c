#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

struct Tabuleiro{
    int tab[TAM_TABULEIRO][TAM_TABULEIRO];
};

tTabuleiro* CriaTabuleiro(){
    tTabuleiro* tabuleiro = malloc(sizeof(tTabuleiro));
     for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro->tab[i][j] = 0;
        }
    }
    return tabuleiro;
}

void DestroiTabuleiro(tTabuleiro* tabuleiro){
    free(tabuleiro);
}

void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){
    tabuleiro->tab[y][x] = peca;
}

int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            if (tabuleiro->tab[i][j] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){
    if (tabuleiro->tab[y][x] == peca)
    {
        return 1;
    }
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    if (tabuleiro->tab[y][x] == 0)
    {
        return 1;
    }
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
    {
        return 1;
    }
    return 0;
}

void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        printf("    ");
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            if (tabuleiro->tab[i][j] == 0)
            {
                printf("-");
            }
            if (tabuleiro->tab[i][j] == 1)
            {
                printf("X");
            }
            if (tabuleiro->tab[i][j] == 2)
            {
                printf("0");
            }
            
        }
        printf("\n");
    }
    
}