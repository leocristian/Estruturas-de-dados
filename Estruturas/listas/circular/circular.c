#include<stdio.h>
#include<stdlib.h>
#include"circular.h"

struct no{
    int info;
    No *prox;
};

No *criarLista(){
    return NULL;
}

No *inserirOrdenado(No *lista, int valor){
    No *novo = (No *)malloc(sizeof(No));
    No *aux = lista;
    No *ant = lista;

    novo->info = valor;

    if(lista == NULL){
        novo->prox = novo;
        return novo;
    }else{
        if(valor<lista->info){
            for (aux=lista->prox; aux->prox != lista; aux = aux->prox);
            novo->prox = lista;
            aux->prox = novo;
            return novo;
        }else{
            aux = lista->prox;
            ant = lista;
            while(aux != lista){
                if(aux->info > valor){
                    ant->prox = novo;
                    novo->prox = aux;
                    break;
                }
                aux = aux->prox;
                ant = ant->prox;
            }
            if(aux == lista){
                ant->prox = novo;
                novo->prox = aux;
            }
        }
    }
    return lista;
}

No *remover(No *lista, int valor){
    No *aux = lista, *ant = lista;

    if(lista == NULL){
        printf("Lista vazia\n");
    }else if(lista->prox == aux){
        free(aux);
        return NULL;
    }if(valor == lista->info){
        for(aux = lista->prox; aux->prox != lista; aux = aux->prox);
        aux->prox = lista->prox;
        aux = lista;
        lista = lista->prox;
        free(aux);
        return lista;
    }else{
        aux = lista->prox;
        ant = lista;

        while(aux != lista){
            if(aux->info == valor){
                ant->prox = aux->prox;
                free(aux);
                break;
            }
            aux = aux->prox;
            ant = ant->prox;
        }
    }
    return lista;
}

void buscar(No *lista, int valor){
    No *aux = lista;

    printf("%d\n", aux->info);
    aux = lista->prox;

    do{
        if(aux->info == valor){
            printf("Achei\n");
        }else{
            printf("%d\n", aux->info);
        }
        aux = aux->prox;
    }while(aux != lista);
}

void mostrar(No *lista){
    No *aux = lista;

    if(aux != NULL){
        do{
            printf("%d\n", aux->info);
            aux = aux->prox;
        } while(aux != lista);
    }else{
        printf("Lista vazia\n");
    }
}

void liberar(No *lista){
    free(lista);
}