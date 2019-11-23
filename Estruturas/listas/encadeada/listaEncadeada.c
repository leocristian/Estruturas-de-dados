#include<stdio.h>
#include<stdlib.h>
#include"listaEncadeada.h"

struct no{
    int info;
    No *prox;
};

No *criarListaEncadeada(){
    printf("Lista criada\n");
    return NULL;
}

No *inserirInicio(No *lista, int v){
    No *novaLista;
    novaLista = (No *)malloc(sizeof(No));
    novaLista->info = v;
    novaLista->prox = lista;

    return novaLista;
}
No *inserirFim(No *lista, int v){
    No *aux, *novo;
    novo = (No *)malloc(sizeof(No));

    novo->info = v;
    for(aux = lista; aux->prox != NULL;aux = aux->prox);
    aux->prox = novo;
    novo->prox = NULL;
    return lista;
}
No *inserirOrdenado(No *lista, int v){
    No *novo, *aux, *ant;
    novo = NULL;
    ant = NULL;
    aux = lista;
    while(aux != NULL && aux->info < v){
        ant = aux;
        aux = aux->prox;
    }
    if(ant == NULL){
        lista = inserirInicio(aux, v);
    }else{
        novo = (No *)malloc(sizeof(No));
        novo->info = v;
        ant->prox = novo;
        novo->prox = aux;
    }
    return lista;
}
No *remover(No *lista, int v){
    No *aux;

    aux = lista;

    if(aux->info == v){
        aux->prox = aux->prox->prox;
    }
    while(aux->prox->info != v){
        aux = aux->prox;
    }

    aux->prox = aux->prox->prox;
    return lista;
}
void mostrarLista(No *lista){
    for (No *aux = lista; aux != NULL; aux = aux->prox){
        printf("%d\n", aux->info);
    }
}
void liberar(No *lista){
    free(lista);
}
void buscar(No *lista, int v){
    No *aux;

    aux = lista;

    while(aux != NULL){
        if(aux->info == v){
            printf("Achei: %d\n", aux->info);
        }
        aux = aux->prox;
    }
}