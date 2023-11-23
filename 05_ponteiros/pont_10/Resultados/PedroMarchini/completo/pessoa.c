#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.irmao = NULL;
    pessoa.pai = NULL;
    return pessoa;
}

void LePessoa(tPessoa *pessoa){
    scanf("\n%[^\n]", pessoa->nome);
    // printf("%s", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if (pessoa->pai != NULL || pessoa->mae != NULL)
    {
        return 1;
    }
    return 0;
}

void ImprimePessoa(tPessoa *pessoa){
    if (VerificaSeTemPaisPessoa(pessoa))
    {
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        
        if (pessoa->pai != NULL)
        {
            printf("PAI: %s\n", pessoa->pai->nome);
        }
        else {
            printf("PAI: NAO INFORMADO\n");
        }

        if (pessoa->mae != NULL)
        {
            printf("MAE: %s\n", pessoa->mae->nome);
        }
        else {
            printf("MAE: NAO INFORMADO\n");
        }

        if (pessoa->irmao != NULL)
        {
            printf("IRMAO: %s\n\n", pessoa->irmao->nome);
        }
        else {
            printf("IRMAO: NAO INFORMADO\n\n");
        }
    }
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    if (pessoa1->mae->nome == pessoa2->mae->nome && pessoa1->pai->nome == pessoa2->pai->nome)
    {
       return 1;
    }
    return 0;
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
    int relacoes;
    int mae, pai, filho;
    scanf("%d\n", &relacoes);
    for (int i = 0; i < relacoes; i++)
    {
        scanf("mae: %d, pai: %d, filho: %d\n", &mae, &pai, &filho);
        if (mae >= 0)
        {
            pessoas[filho].mae = &pessoas[mae];
        }
        if (pai >= 0)
        {
            pessoas[filho].pai = &pessoas[pai];
        }
    }

    for (int i = 0; i < numPessoas; i++)
    {
        for (int j = 0; j < numPessoas; j++)
        {
            if (VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]))
        {
            if (i != j)
            {
            pessoas[i].irmao = &pessoas[j];
            pessoas[j].irmao = &pessoas[i];
            }
        }
        }
        
    }
}