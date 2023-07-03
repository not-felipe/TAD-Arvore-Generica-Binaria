#ifndef _ARVORE_BINARIA_
#define _ARVORE_BINARIA_

typedef struct arvore arvore;

arvore* inserirElemento(arvore* arvoreRaiz, void* info, int chave, int chavePai, char posicao);
int existeElemento(arvore *a, int chave);
void* buscarElemento(arvore *a, int chave);
int balanceada(arvore* a);
int altura(arvore* a);
void imprimirEmLargura(arvore* a);
void freeArvore(arvore* a);

#endif