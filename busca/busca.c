#include "busca.h"

/** \brief Funcao que compara dois elementos inteiros
 * \author Jaicimara Weber
 * \date   22/05/2015
 * \param const void* n1,const void* n2
 * \return 1 n1 > n2, -1 n1 < n2 e 0 n1 = n2 *
 */
int comp_int (const void* n1, const void* n2)
{
    /* converte ponteiros genéricos para ponteiros de int */
    int *i1 = (int*)n1;
    int *i2 = (int*)n2;
    /* dados os ponteiros de int, faz a comparação */
    if (*i1 < *i2)
        return -1;
    else if (*i1 > *i2)
        return 1;
    else
        return 0;
}
/** \brief Funcao que compara coordena do centro de uma circunferencia
 * \author Jaicimara Weber
 * \date   22/05/2015
 * \param const void* n1,const void* n2
 * \return 1 n1 > n2, -1 n1 < n2 e 0 n1 = n2 *
 */
int comp_ponto (const void* x1, const void* x2,const void* y1, const void* y2)
{
    /* converte ponteiros genéricos para ponteiros de int */
    float *ix1 = (float*)x1;
    float *ix2 = (float*)x2;
    float *iy1 = (float*)x2;
    float *iy2 = (float*)y2;
    /* dados os ponteiros de int, faz a comparação */

   if(*iy1 == *iy2 && *ix1 == *ix2)
        return 0;
   else
        return 1;

   /* if (*iy1 < *iy2)
        return -1;
    else if (*iy1 > *iy2)
        return 1;
    else if (*iy1== *iy2 && *ix1 < *ix2)
        return -1;
    else if (*iy1== *iy2 && *ix1 > *ix2)
        return 1;
    else
        return 0;*/
}

/**
 * \brief Funcao insere vetor de circulo ordenado pelo ponto do centro.
 * \author Jaicimara Weber
 * \date   22/05/2015
 * \param const int x, const int y, const int r
 */
void insereCirculoOrdenado(const int x, const int y, const int r, CIRC* vetor, int n)
{
    int i,flagEncontrado = 0,posicao = 0;
    for(i = 0; i <= n; i++){
        /*varredura no array para comparar os valores */
        if(vetor[i].y > y){
            flagEncontrado = 1;
            posicao = i;
            break;
        }else if (vetor[i].y == y && vetor[i].x > x){
            flagEncontrado = 1;
            posicao = i;
            break;
        }
    }
    if(flagEncontrado){
        for(i=n; i >= posicao;i--){
            vetor[i+1].raio = vetor[i].raio;
            vetor[i+1].y = vetor[i].y;
            vetor[i+1].x = vetor[i].x;
        }
        vetor[posicao].raio = r;
        vetor[posicao].x = x;
        vetor[posicao].y = y;
    }else{
        vetor[n+1].raio = r;
        vetor[n+1].x = x;
        vetor[n+1].y = y;
    }
}
