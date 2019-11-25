#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fila.h"

struct no{
    int idade;
    char nome[10];
    No *prox;
};
struct fila{
    No *inicio;
    No *fim;
};

Fila *criarFila(Fila *f){
    Fila *novo = (Fila *)malloc(sizeof(Fila));

    novo->inicio = NULL;
    novo->fim = novo->inicio;

    return novo;
}

void inserirFila(Fila *f, int valor, char nome[]){
    No *novo = (No *)malloc(sizeof(No));

    novo->idade = valor;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if(f->fim != NULL){
        f->fim->prox = novo;
    }else{
        f->inicio = novo;
    }
    f->fim = novo;
}
void removerFila(Fila *f){
    No *aux = f->inicio;
    f->inicio = aux->prox;
    if(f->inicio == NULL)
        f->fim = f->inicio;
    free(aux);
}
void mostrar(Fila *f){
    if(f->inicio == NULL){
        printf("Fila Vazia.\n");
    }else{
        printf("----Inicio----\n");
        printf("Idade : %d\nnome: %s\n", f->inicio->idade, f->inicio->nome);
        printf("----Fim----\n");
        printf("Idade : %d\nnome: %s\n", f->fim->idade, f->fim->nome);
    }
}
void liberar(Fila *f){
    while(f->inicio != NULL){
        No *aux = f->inicio;
        f->inicio = aux->prox;
        free(aux);
    }
    free(f);
}