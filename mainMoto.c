#include "arvore.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct moto{
    int ano;
    char modelo[50];
    char placa[10];
    char cor[20];
    int numeroSerie;
} Moto;

void menuMoto() {
    printf("[1] Inserir Moto\n");
    printf("[2] Verificar Existencia\n");
    printf("[3] Buscar Moto\n");
    printf("[4] Verificar Balanceamento\n");
    printf("[5] Calcular Altura\n");
    printf("[6] Imprimir em Largura\n");
    printf("[0] Sair\n");
    printf("[->] ");
}

int main() {

    arvore* arvoreMotos = NULL;

    int option = 9;

    do {

        menuMoto();
        scanf("%d", &option);

        switch (option) {

            case 1: {

                int chavePai;
                char posicao;
                Moto* novaMoto = (Moto*)malloc(sizeof(Moto));
                printf("Digite o ano da moto: ");
                scanf("%d", &(novaMoto->ano));
                printf("Digite o modelo da moto: ");
                scanf("%s", novaMoto->modelo);
                printf("Digite a placa da moto: ");
                scanf("%s", novaMoto->placa);
                printf("Digite a cor da moto: ");
                scanf("%s", novaMoto->cor);
                printf("Digite o numero de serie da moto: ");
                scanf("%d", &(novaMoto->numeroSerie));
                printf("Digite a chave do pai do elemento (-1, caso seja o primeiro): ");
                scanf("%d", &chavePai);
                printf("Deseja inserir o elemento na esquerda ou na direita? (Digite 'd' para direita e 'e' para esquerda): ");
                scanf(" %c", &posicao);

                // Insere a moto na árvore
                arvoreMotos = inserirElemento(arvoreMotos, novaMoto, novaMoto->numeroSerie, chavePai, posicao);

                printf("Moto inserida com sucesso!\n\n");
                system("Pause");
                system("cls");
                break;
            }
            case 2: {

                int chave;
                printf("Digite a chave da moto que deseja verificar: ");
                scanf("%d", &chave);

                if (existeElemento(arvoreMotos, chave))
                    printf("Moto com chave %d existe na árvore.\n", chave);
                else
                    printf("Moto com chave %d não existe na árvore.\n", chave);
                
                system("Pause");
                system("cls");
                break;
            }
            case 3: {

                int chave;
                printf("Digite o chassi que deseja buscar: ");
                scanf("%d", &chave);

                void *elemento = buscarElemento(arvoreMotos, chave);
                if (elemento != NULL) {

                    Moto* moto = (Moto*)elemento;
                    printf("Moto encontrada!\n");
                    printf("Ano: %d\n", moto->ano);
                    printf("Modelo: %s\n", moto->modelo);
                    printf("Placa: %s\n", moto->placa);
                    printf("Cor: %s\n", moto->cor);
                    printf("Numero de serie: %d\n", moto->numeroSerie); 
                }

                system("Pause");
                system("cls");

                break;
            }

            case 4: {

                if (balanceada(arvoreMotos))
                    printf("A árvore de motos está balanceada.\n");
                else
                    printf("A árvore de motos não está balanceada.\n");

                break;
                system("Pause");
                system("cls");
            }
            case 5: {

                int h = altura(arvoreMotos);
                printf("Altura da árvore de motos: %d\n", h);
                break;

                system("Pause");
                system("cls");
            }
            case 6: {

                printf("Imprimindo árvore de motos em largura:\n");
                imprimirEmLargura(arvoreMotos);
                printf("\n");
                break;
            }
            case 0: {

                printf("Encerrando o programa...\n");
                freeArvore(arvoreMotos);
                break;
                system("Pause");
                system("cls");
            }
            default:

                printf("Opção inválida!\n");
                system("Pause");
                system("cls");
                break;
        }
    } while (option != 0);

    return 0;
}