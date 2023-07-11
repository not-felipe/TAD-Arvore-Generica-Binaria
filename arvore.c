#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
    void* info;
    int chave;
    struct arvore* dir;
    struct arvore* esq;
} arvore;

int existeElemento(arvore* a, int chave) {
    if (a == NULL)
        return 0;
    else if (a->chave == chave)
        return 1;
    else {
        int encontrado = existeElemento(a->esq, chave);
        if (encontrado)
            return 1;
        return existeElemento(a->dir, chave);
    }
}

void* buscarElemento(arvore* a, int chave) {
    if (a == NULL)
        return NULL;
    if (a->chave == chave) {
        printf("Chave encontrada: %d\n", chave);
        return a->info;
    }
    void* encontrado = buscarElemento(a->esq, chave);
    if (encontrado != NULL)
        return encontrado;
    encontrado = buscarElemento(a->dir, chave);
    if (encontrado != NULL)
        return encontrado;
    return NULL;
}

arvore* encontrarNo(arvore* no, int chave) {
    if (no == NULL || no->chave == chave)
        return no;
    arvore* noEncontrado = encontrarNo(no->esq, chave);
    if (noEncontrado != NULL)
        return noEncontrado;
    return encontrarNo(no->dir, chave);
}

arvore* inserirElemento(arvore* arvoreRaiz, void* info, int chave, int chavePai, char posicao) {
    arvore* novoNo = (arvore*)malloc(sizeof(arvore));
    novoNo->info = info;
    novoNo->chave = chave;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    if (arvoreRaiz == NULL) {
        return novoNo;
    }

    arvore* pai = encontrarNo(arvoreRaiz, chavePai);
    if (pai == NULL) {
        printf("No pai nao existe na arvore!\n");
        return arvoreRaiz;
    }

    if (posicao == 'e') {
        if (pai->esq != NULL) {
            printf("Ja existe um no nesta posicao! Tente inserir em outra.\n");
            return arvoreRaiz;
        }
        pai->esq = novoNo;
    } else if (posicao == 'd') {
        if (pai->dir != NULL) {
            printf("Ja existe um no nesta posicao! Tente inserir em outra.\n");
            return arvoreRaiz;
        }
        pai->dir = novoNo;
    } else {
        printf("Posicao invalida!\n");
        return arvoreRaiz;
    }

    return arvoreRaiz;
}

int balanceada(arvore* a) {
    if (a == NULL)
        return 1;
    int alturaEsq = altura(a->esq);
    int alturaDir = altura(a->dir);
    if (abs(alturaEsq - alturaDir) <= 1 && balanceada(a->esq) && balanceada(a->dir))
        return 1;
    return 0;
}

int altura(arvore* a) {
    if (a == NULL)
        return 0;
    int alturaEsq = altura(a->esq);
    int alturaDir = altura(a->dir);
    return (alturaEsq > alturaDir) ? (alturaEsq + 1) : (alturaDir + 1);
}

void imprimirNivel(arvore* a, int cont, int nivel) {
    if (a != NULL) {
        if (cont == nivel)
            printf("%d ", a->chave);
        else {
            imprimirNivel(a->esq, cont + 1, nivel);
            imprimirNivel(a->dir, cont + 1, nivel);
        }
    }
}

void imprimirEmLargura(arvore* a) {
    if (a != NULL) {
        int i;
        int h = altura(a);
        for (i = 0; i < h; i++) {
            imprimirNivel(a, 0, i);
            printf("\n");
        }
    }
}

void freeArvore(arvore* a) {
    if (a == NULL)
        return;
    freeArvore(a->esq);
    freeArvore(a->dir);
    free(a);
}
