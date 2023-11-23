#include "jogador.h"
#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>

struct Jogador{
    int id;
    tJogada* jogada;
    int x, y;
};

tJogador* CriaJogador(int idJogador){
    tJogador* jogador = malloc(sizeof(tJogador));

    if (jogador == NULL)
    {
        printf("Erro na alocacao dinamica\n");
        exit(1);
    }

    jogador->id = idJogador;
    return jogador;
}

void DestroiJogador(tJogador* jogador){
    free(jogador);
}

void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    LeJogada(jogador->jogada);
}

int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro){


    // Verificar linhas
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        int vitoria = 1;
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador->id)) {
                vitoria = 0;
                break;
            }
        }
        if (vitoria) return 1;
    }

    // Verificar colunas
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        int vitoria = 1;
        for (int i = 0; i < TAM_TABULEIRO; i++) {
            if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador->id)) {
                vitoria = 0;
                break;
            }
        }
        if (vitoria) return 1;
    }

    // Verificar diagonal principal
    int vitoriaPrincipal = 1;
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, i, jogador->id)) {
            vitoriaPrincipal = 0;
            break;
        }
    }
    if (vitoriaPrincipal) return 1;

    // Verificar diagonal secundária
    int vitoriaSecundaria = 1;
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, TAM_TABULEIRO - i - 1, jogador->id)) {
            vitoriaSecundaria = 0;
            break;
        }
    }
    if (vitoriaSecundaria) return 1;

    // Nenhuma condição de vitória encontrada
    return 0;
}