#include<stdio.h>
#include<stdlib.h>
#include"dupla.h"

struct no{
    int info;
    No *prox;
    No *ant;
};

No *criarLista(){
    return NULL;
}

No *inserirOrdenado(No *lista, int valor){
    No *novo = (No *)malloc(sizeof(No));
    novo->info = valor;
    novo->prox = lista;
    novo->ant = NULL;
    if(lista != NULL){
        lista->ant = novo;
    }
    return novo;
}

void buscar(No *lista, int valor){
    No *aux = lista;
    while(aux != NULL){
        if(aux->info == valor){
            puts("Achei");
        }else{
            printf("%d\n", aux->info);
        }
        aux = aux->prox;
    }
}

No *remover(No *lista, int valor){
    No *aux = lista, *pos;

    while(aux != NULL){
        if(aux->info == valor){
            pos = aux;
        }
        aux = aux->prox;
    }
    if(lista == NULL){
        return lista;
    }if(lista == pos){
        lista = pos->prox;
    }else{
        pos->ant->prox = pos->prox;
    }if(pos->prox != NULL){
        pos->prox->ant = pos->ant;
    }
    free(pos);

    return lista;
}
void mostrarLista(No *lista){
    No *aux = lista;

    while(aux != NULL){
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}
void liberar(No *lista){
    while(lista != NULL){
        free(lista);
        lista = lista->prox;
    }
}