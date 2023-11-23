#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int num;
    scanf("%d", &num);
    tPessoa pessoa[num];

    for (int i = 0; i < num; i++)
    {
        pessoa[i] = CriaPessoa();
    }


    for (int i = 0; i < num; i++)
    {
        LePessoa(&pessoa[i]);
    }

    AssociaFamiliasGruposPessoas(&pessoa, num);
    for (int i = 0; i < num; i++)
    {
        ImprimePessoa(&pessoa[i]);
    }
    
    return 0;
}