#include "arvore.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct {

    char raca[50];
    char porte[20];
    char tipo[20];
    char classe[20];
    char especie[50];
    int id;
} Animal;

void menu() {

    printf("[1] Inserir Animal\n");
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
                Animal* animal = (Animal*) malloc(sizeof(Animal));
                printf("Digite a raca do animal: ");
                scanf("%s", animal->raca);
                printf("Digite o porte do animal: ");
                scanf("%s", animal->porte);
                printf("Digite o tipo do animal: ");
                scanf("%s", animal->tipo);
                printf("Digite a classe do animal: ");
                scanf("%s", animal->classe);
                printf("Digite a especie do animal: ");
                scanf("%s", animal->especie);
                printf("Digite o ID do animal: ");
                scanf("%d", &animal->id);
                printf("Digite a chave do pai do elemento (-1, caso seja o primeiro): ");
                scanf("%d", &chavePai);
                printf("Deseja inserir o elemento na esquerda ou na direita? (Digite 'd' para direita e 'e' para esquerda): ");
                scanf(" %c", &posicao);
                raiz = inserirElemento(raiz, animal, animal->id, chavePai, posicao);
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
                system("Pause");
                system("cls");
                break;
            }
            case 3: {

                int chave;
                printf("Digite a chave que deseja buscar: ");
                scanf("%d", &chave);

                void* elemento = buscarElemento(raiz, chave);
                if (elemento != NULL) {
                    Animal* animalEncontrado = (Animal*) elemento;
                    printf("Informacoes do animal:\n");
                    printf("Raca: %s\n", animalEncontrado->raca);
                    printf("Porte: %s\n", animalEncontrado->porte);
                    printf("Tipo: %s\n", animalEncontrado->tipo);
                    printf("Classe: %s\n", animalEncontrado->classe);
                    printf("Especie: %s\n", animalEncontrado->especie);
                    printf("ID: %d\n", animalEncontrado->id);
                }
                system("Pause");
                system("cls");
                break;
            }
            case 4:

                if (balanceada(raiz))
                    printf("A arvore esta balanceada!\n");
                else
                    printf("A arvore nao esta balanceada!\n");
                break;
            case 5:

                printf("Altura da arvore: %d\n", altura(raiz));
                break;
            case 6:

                imprimirEmLargura(raiz);
                system("Pause");
                system("cls");
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
