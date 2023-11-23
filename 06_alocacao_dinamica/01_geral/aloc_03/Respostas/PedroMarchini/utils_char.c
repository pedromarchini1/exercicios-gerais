#include "utils_char.h"
#include <stdio.h>
#include <stdlib.h>

char *CriaVetor(int tamanho){
    char* vetor = malloc(tamanho*sizeof(char));
    if (vetor == NULL)
    {
        printf("erro de alocacao\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = '_';
    }
    
    return vetor;
}

void LeVetor(char *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%c", &vetor[i]);
    }
}

void ImprimeString(char *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] != '\n')
        {
            printf("%c", vetor[i]);
        }
        else{
            printf("_");
        }
    }
    printf("\n");
}

void LiberaVetor(char *vetor){
    free(vetor);
}