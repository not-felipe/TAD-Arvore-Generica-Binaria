#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int kcal;
    char tipoAlimento[20];
    float preco;
    int id;
} Alimento;

void menu() {
    printf("[1] Inserir Alimento\n");
    printf("[2] Verificar se um elemento existe\n");
    printf("[3] Buscar um elemento\n");
    printf("[4] Verificar se a arvore esta balanceada\n");
    printf("[5] Calcular a altura da arvore\n");
    printf("[6] Imprimir a arvore em largura\n");
    printf("[0] Sair do Programa\n");
    printf("[->] ");
}

int main() {

    int option = 9;
    arvore* raiz = NULL;

    do {

        menu();
        scanf("%d", &option);

        switch (option) {

            case 1: {

                int chavePai;
                char posicao;
                Alimento* alimento = (Alimento*) malloc(sizeof(Alimento));
                printf("Digite o valor em kcal do alimento: ");
                scanf("%d", &alimento->kcal);
                printf("Digite o tipo de alimento: ");
                scanf(" %s", &alimento->tipoAlimento);
                printf("Digite o preco do alimento: ");
                scanf("%f", &alimento->preco);
                printf("Digite o ID do alimento: ");
                scanf("%d", &alimento->id);
                printf("Digite a chave do pai do elemento (-1, caso seja o primeiro): ");
                scanf("%d", &chavePai);
                printf("Deseja inserir o elemento na esquerda ou na direita? (Digite 'd' para direita e 'e' para esquerda): ");
                scanf(" %c", &posicao);
                raiz = inserirElemento(raiz, alimento, alimento->id, chavePai, posicao);
                system("Pause");
                system("cls");
                break;
            }
            case 2: {

                int chave;
                printf("Digite a chave que deseja verificar: ");
                scanf("%d", &chave);
                if (existeElemento(raiz, chave))
                    printf("Chave %d existe!\n", chave);
                else
                    printf("Chave %d nao existe!\n", chave);
                break;
                system("Pause");
                system("cls");
            }
            case 3: {

                int chave;
                printf("Digite a chave que deseja buscar: ");
                scanf("%d", &chave);

                void* elemento = buscarElemento(raiz, chave);
                if (elemento != NULL) {

                    Alimento* alimentoEncontrado = (Alimento*) elemento;
                    printf("Informacoes do alimento:\n");
                    printf("Valor em kcal: %d\n", alimentoEncontrado->kcal);
                    printf("Tipo de alimento: %s\n", alimentoEncontrado->tipoAlimento);
                    printf("Preco: %.2f\n", alimentoEncontrado->preco);
                    printf("ID: %d\n", alimentoEncontrado->id);
                    system("Pause");
                    system("cls");
                    
                }
                break;
            }
            case 4:

                if (balanceada(raiz)){
                    printf("A arvore esta balanceada!\n");
                    system("Pause");
                    system("cls");
                }
                else{
                    printf("A arvore nao esta balanceada!\n");
                    system("Pause");
                    system("cls");
                }
                break;
            case 5:

                printf("Altura da arvore: %d\n", altura(raiz));
                system("Pause");
                system("cls");
                break;
            case 6:

                imprimirEmLargura(raiz);
                break;
            case 0:

                printf("Encerrando programa!\n");
                freeArvore(raiz);
                system("Pause");
                system("cls");
                break;
            default:

                printf("Opcao invalida!\n");
                system("Pause");
                system("cls");
                

                break;
        }
    } while (option != 0);

    return 0;
}
