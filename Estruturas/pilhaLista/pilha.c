#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

struct no{
    int info;
    No *prox;
};

struct pilha{
    No *prim;
};

Pilha *criarPilha(){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->prim = NULL;

    return p;
}
void pushPilha(Pilha *p, int valor){
    No *novo = (No *)malloc(sizeof(No));

    novo->info = valor;
    novo->prox = p->prim;
    p->prim = novo;
}
int popPilha(Pilha *p){
    No *aux;
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
    No *primeiro = p->prim;
    
    while(primeiro != NULL){
        No *aux = primeiro->prox;
        free(primeiro);

        primeiro = aux;
    }
    free(p);
}