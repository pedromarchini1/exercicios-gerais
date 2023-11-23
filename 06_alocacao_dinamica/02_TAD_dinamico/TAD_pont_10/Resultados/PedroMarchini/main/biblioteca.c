#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tBiblioteca* InicializarBiblioteca(){
    tBiblioteca* biblioteca = malloc(sizeof(biblioteca));
    for (int i = 0; i < 10; i++)
    {
        biblioteca->livros[i] = CriaLivro();
    }
    biblioteca->tamanho = 0;
    return biblioteca;
}

void ApagaBiblioteca(tBiblioteca* biblioteca){
    for (int i = 0; i < biblioteca->tamanho; i++) {
        ApagaLivro(biblioteca->livros[i]);
    }
    free(biblioteca);
}

void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro){
    if (biblioteca->tamanho < 10)
    {
        LerLivro(biblioteca->livros[biblioteca->tamanho]);
        printf("Livro adicionado com sucesso!\n");
        biblioteca->tamanho++;
    }
    else {
        printf("A biblioteca está cheia. Não é possível adicionar mais livros.\n");
    }
}

void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo){
    for (int i = 0; i < biblioteca->tamanho; i++)
    {
        if (VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo))
        {
            ApagaLivro(biblioteca->livros[i]);
        }
        else {
            printf("Livro nao encontrado na biblioteca.\n");
        }
    }
}

int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo){
    if (strcmp(livro->titulo, titulo))
    {
        return 1;
    }
    return 0;
}

void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca){
    for (int i = 0; i < biblioteca->tamanho; i++)
    {
        ImprimeLivro(biblioteca->livros[i]);
    }
}