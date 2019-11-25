#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

struct no{
    int info;
    No *prox;
};

struct fila{
    No *inicio;
    No *fim;
};

Fila *criarFila(){
    Fila *f = (Fila *)malloc(sizeof(Fila));

    f->inicio = f->fim = NULL;
    return f;
}
void inserirFila(Fila *f, int valor){
    No *novo = (No *)malloc(sizeof(No));

    novo->info = valor;
    novo->prox = NULL;
    if(f->fim != NULL){
        f->fim->prox = novo;
    }else{
        f->inicio = novo;
    }
    f->fim = novo;
}
void removerFila(Fila *f){
    No *aux;

    if(f->inicio->prox == NULL && f->fim->prox == NULL){
        printf("Lista Vazia.\n");
        exit(1);
    }
    aux = f->inicio;
    f->inicio = aux->prox;
    printf("Valor removido: %d\n", aux->info);
    free(aux);
}
void liberarFila(Fila *f){
    while(f->inicio != NULL){
        free(f->inicio);
        f->inicio = f->inicio->prox;
    }
    free(f);
}
void mostrar(Fila *f){
    // printf("Inicio: %d\n", f->inicio->info);
    // printf("Final: %d\n", f->fim->info);
    printf("Fila: ");
    for (No *aux = f->inicio; aux != NULL; aux = aux->prox)
        printf("%d ", aux->info);
    printf("\n");
}