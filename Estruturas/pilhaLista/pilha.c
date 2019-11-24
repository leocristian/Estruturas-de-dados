#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

struct lista{
    int info;
    Lista *prox;
};

struct pilha{
    Lista *prim;
};

Pilha *criarPilha(){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->prim = NULL;

    return p;
}
void pushPilha(Pilha *p, int valor){
    Lista *novo = (Lista *)malloc(sizeof(Lista));

    novo->info = valor;
    novo->prox = p->prim;
    p->prim = novo;
}
int popPilha(Pilha *p){
    Lista *aux;
    int valor;

    if(p->prim == NULL){
        printf("Pilha vazia.\n");
    }
    aux = p->prim;
    valor = aux->info;
    p->prim = aux->prox;
    free(aux);

    return valor;
}
void topo(Pilha *p){
    printf("Topo da pilha: %d\n", p->prim->info);
}
void liberar(Pilha *p){
    while(p->prim != NULL){
        free(p->prim);
        p->prim = p->prim->prox;
    }
}