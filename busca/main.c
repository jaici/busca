#include <stdio.h>
#include <stdlib.h>
#include "busca.h"

#define SIZE_VECTOR 10

int main()
{
    CIRC vetor[SIZE_VECTOR];
    CIRC busca;
    int i;
    int x,y,r;
    int* p;

    busca.raio = 0;
    busca.x = 40;
    busca.y = 63;

    for(i=0;i<SIZE_VECTOR;i++){
        x = (rand()%127);
        y = (rand()%127);
        r = (rand()%127);
        insereCirculoOrdenado(x,y,r,vetor,i);
    }

    p = (CIRC*) bsearch(&busca,vetor,(sizeof(vetor)/sizeof(vetor[0])),sizeof(CIRC), comp_int);

    for(i=0;i<SIZE_VECTOR;i++){
       printf("X:%d\tY:%d \n",vetor[i].x,vetor[i].y);
    }
    if(p == NULL){
        printf("\nNAO ENCONTROU\n");
    }else{
        printf("\nLOCALIZOU PONTO\ns");
    }
    return 0;
}
