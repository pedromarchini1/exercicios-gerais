#include "livro.h"
#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtd;
    char titulo[1000];
    tBiblioteca* biblioteca;
    scanf("%d", &qtd);
    int operacao;

    biblioteca = InicializarBiblioteca();
    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n\n");
    for (int i = 0; i < qtd; i++)
    {
        scanf("%d", &operacao);
        printf("%d\n", operacao);
        // if (operacao[i] == 1)
        // {
        //    AdicionarLivroNaBiblioteca(&biblioteca, &biblioteca->livros);
        // }
        // if (operacao[i] == 2)
        // {
        //    scanf(" %[^\n]\n", titulo);
        //    RemoverLivroDaBiblioteca(biblioteca, titulo);
        // }
        //if (operacao[i] == 3)
        //{
          //  ListarLivrosDaBiblioteca(biblioteca);
        //}
    }
    ApagaBiblioteca(biblioteca);
    return 0;
}