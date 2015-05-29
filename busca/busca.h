#ifndef BUSCA_H_INCLUDED
#define BUSCA_H_INCLUDED

typedef struct circle CIRC;
struct circle{
    int x,y,raio;
};

int comp_int (const void* n1, const void* n2);
void insereCirculoOrdenado(const int x, const int y, const int r, CIRC* vetor, int n );
int comp_ponto (const void* x1, const void* x2,const void* y1, const void* y2);
#endif // BUSCA_H_INCLUDED
