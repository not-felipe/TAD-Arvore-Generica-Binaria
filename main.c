#include "arvore.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Aluno{
  int matricula;
  char nome[50];
} aluno;

void menu(){
  printf("[1] Inserir Elemento\n");
  printf("[2] Verificar se um elemento existe\n");
  printf("[3] Buscar um elemento\n");
  printf("[4] Verificar se a arvore esta balanceada\n");
  printf("[5] Calcular a altura da arvore\n");
  printf("[6] Imprimir a arvore em largura\n");
  printf("[0] Sair do Programa\n");
  printf("[->] ");
}

int main(){

  int option = 9;
  arvore* raiz = NULL;

  do{
    menu();
    scanf("%d", &option);

    switch(option){
      case 1:{
        int chavePai;
        char posicao;
        aluno* aluno1 = (aluno*) malloc(sizeof(aluno));
        printf("Digite a matricula do aluno: ");
        scanf("%d", &aluno1->matricula);
        printf("Digite o nome do aluno: ");
        scanf("%s", aluno1->nome);
        printf("Digite a chave do pai do elemento (-1, caso seja o primeiro): ");
        scanf("%d", &chavePai);
        printf("Deseja inserir o elemento na esquerda ou na direita? (Digite 'd' para direita e 'e' para esquerda): ");
        scanf(" %c", &posicao);
        raiz = inserirElemento(raiz, aluno1, aluno1->matricula, chavePai, posicao);
        break;
      }
      case 2:{
        int chave;
        printf("Digite a chave que deseja verificar: ");
        scanf("%d", &chave);
        if(existeElemento(raiz, chave)) printf("Chave %d existe!\n", chave);
        else printf("Chave %d nao existe!\n", chave);
        break;
      }
      case 3:{
        int chave;
        printf("Digite a chave que deseja buscar: ");
        scanf("%d", &chave);

        void *elemento = buscarElemento(raiz, chave);
        if(elemento != NULL) {
          aluno *alunoEncontrado = (aluno*)elemento;
          printf("Informacoes do aluno:\n");
          printf("Matricula: %d\n", alunoEncontrado->matricula);
          printf("Nome: %s\n", alunoEncontrado->nome);
        }  
        break;
      }
      case 4:
        if(balanceada(raiz)) printf("A arvore esta balanceada!\n");
        else printf("A arvore nao esta balanceada!\n");
        break;
      case 5:
        printf("Altura da arvore: %d\n", altura(raiz));
        break;
      case 6:
        imprimirEmLargura(raiz);
        break;
      case 0:
        printf("Encerrando programa!\n");
        freeArvore(raiz);
        break;
      default:
        printf("Opcao invalida!\n");
        break;
    }
  }while(option != 0);

  return 0;
}
