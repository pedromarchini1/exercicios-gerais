#include "livro.h"
#include <stdio.h>
#include <stdlib.h>

tLivros* CriaLivro(){
    tLivros* livro = malloc(sizeof(livro));
    livro->anoPublicacao = -1;
    livro->titulo = NULL;
    livro->autor = NULL;
    return livro;
}

void LerLivro(tLivros* livro){
    scanf("%[^\n]\n", &livro->titulo);
    scanf("%[^\n]\n", &livro->autor);
    scanf("%d", &livro->anoPublicacao);
}

void ImprimeLivro(tLivros* livro){
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n\n", livro->anoPublicacao);
}

void ApagaLivro(tLivros* livro){
    free(livro);
}