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
void mostrar(Fila *f){
    printf("Inicio: %d\n", f->inicio->info);
    printf("Final: %d\n", f->fim->info);
}