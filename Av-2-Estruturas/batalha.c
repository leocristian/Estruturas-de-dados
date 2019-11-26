#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"batalha.h"

#define max 32
#define N 20

struct lutador{
    char nome[50];
    int forca;
    int raca;
    float altura;
    float peso;
    int cenario_guerreiro;
    int fraqueza;
    int especialidade;
    Lutador *prox;
};
struct fila{
    Lutador *inicio;
    Lutador *fim;
};
struct pilha{
    Lutador *primeiro;
};
Fila *criarFila(){
    Fila *novo = (Fila *)malloc(sizeof(Fila));

    novo->inicio = NULL;
    novo->fim = NULL;

    return novo;
}
Pilha *criarPilha(){
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->primeiro = NULL;
    return novo;
}
void inserirLutador(Fila *disponiveis, char nome[], float altura, float peso){
    Lutador *novo = (Lutador *)malloc(sizeof(Lutador));
    strcpy(novo->nome, nome);
    novo->raca = 1+(rand()%1000)/N;
    novo->altura = altura;
    novo->forca = 0;
    novo->peso = peso;
    novo->cenario_guerreiro = (rand()%10);
    novo->fraqueza = (rand()%100)/novo->cenario_guerreiro;
    novo->prox = NULL;
    if(disponiveis->fim != NULL){
        disponiveis->fim->prox = novo;
    }else{
        disponiveis->inicio = novo;
    }
    disponiveis->fim = novo;
}
void calcularForcas(Fila *lutadores){
    float maiorAltura, menorAltura;
    float maiorPeso, menorPeso;

    Lutador *aux = lutadores->inicio;

    if(aux == NULL){
        printf("Lista vazia.\n");
        exit(1);
    }
    maiorAltura = menorAltura = lutadores->inicio->altura;
    maiorPeso = menorPeso = lutadores->inicio->peso;

    do{
        if(aux->altura > maiorAltura){
            maiorAltura = aux->altura;
        }if(aux->altura < menorAltura){
            menorAltura = aux->altura;
        }
        if(aux->peso > maiorPeso){
            maiorPeso = aux->peso;
        }if(aux->peso < menorPeso){
            menorPeso = aux->peso;
        }
        aux->forca = ((maiorAltura - menorAltura)/(maiorPeso - menorPeso)) *  aux->raca;
        aux = aux->prox;
    }while(aux != NULL);
    //printf("menor altura: %.1f, maior altura: %.1f\n", menorAltura, maiorAltura);
    //printf("menor peso: %.1f, maior peso: %.1f\n", menorPeso, maiorPeso);

}
void mostrarLutadores(Fila *lutadores){
    Lutador *aux = lutadores->inicio;
    if(lutadores->inicio == NULL){
        printf("Não existem lutadores cadastrados.\n");
    }else{
        do{
            printf("Nome: %s forca:%d\n", aux->nome, aux->forca);
            aux = aux->prox;
        }while(aux != NULL);
    }
}
void mostrarPerdedores(Pilha *perdedores){
    Lutador *aux = perdedores->primeiro;
    if(perdedores->primeiro == NULL){
        printf("Ainda não existem perdedores.\n");
    }else{
        printf("Lista de perdedores\n");
        do{
            printf("Nome: %s forca:%d\n", aux->nome, aux->forca);
            aux = aux->prox;
        }while(aux != NULL);
    }
}
void realizarLuta(Fila *lutadores, Pilha *perdedores){
    if(lutadores->inicio == NULL || lutadores->inicio->prox == NULL){
        printf("Não existem lutadores suficientes.\n");
    }else{
        int pontos1, pontos2;
        int cenarioLuta;
        Lutador *novo = (Lutador *)malloc(sizeof(Lutador));
        do{
            Lutador *l1 = lutadores->inicio, *l2 = lutadores->inicio->prox, *vencedor, *aux;
            cenarioLuta = 1+rand()%10;
            l1->especialidade = 1+(rand()%100)/cenarioLuta;
            l2->especialidade = 1+(rand()%100)/cenarioLuta;

            printf("------LUTA------\n");
            printf("%s X %s\n", l1->nome, l2->nome);
            printf("Forca: %d   Forca: %d\n", l2->forca, l2->forca);

            pontos1 = (l1->forca - l1->fraqueza) * (l1->especialidade/N);
            pontos2 = (l2->forca - l2->fraqueza) * (l2->especialidade/N);

            if(pontos1 > pontos2){
                vencedor = l1;
                aux = l2;
                aux->prox = perdedores->primeiro;
                perdedores->primeiro = aux;
            }else{
                vencedor = l2;
                aux = l1;
                aux->prox = perdedores->primeiro;
                perdedores->primeiro = aux;
            }
            printf("nome do vencedor: %s\n", vencedor->nome);
            l1 = l2->prox;
            l2 = l1->prox;
            lutadores->inicio = lutadores->inicio->prox;
        }while(lutadores->inicio != NULL);
    }
}
void liberar(Fila *lutadores){
    while(lutadores->inicio != NULL){
        free(lutadores->inicio);
        lutadores->inicio = lutadores->inicio->prox;
    }
    free(lutadores);
}