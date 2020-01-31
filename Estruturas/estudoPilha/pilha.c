#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pilha.h"

struct no{
    int info;
    char nome[10];
    No *prox;
};
struct pilha{
    No *primeiro;
};

Pilha *criarPilha(){
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));

    novo->primeiro = NULL;

    return novo;
}
void inserirPilha(Pilha *p, int valor, char nome[]){
    No *novo = (No *)malloc(sizeof(No));

    novo->info = valor; 
    strcpy(novo->nome, nome);
    novo->prox = p->primeiro;
    p->primeiro = novo;
}
void removerPilha(Pilha *p){
    if(p->primeiro == NULL){
        printf("Lista vazia.\n");
    }else{
        No *aux = p->primeiro;
        p->primeiro = aux->prox;
        free(aux);
    }
}
void liberar(Pilha *p){
    while(p->primeiro != NULL){
        p->primeiro = p->primeiro->prox;
        free(p->primeiro);
    }
    free(p);
}
void mostrar(Pilha *p){
    if(p->primeiro == NULL){
        printf("Lista vazia.\n");
    }else{
    printf("Topo da pilha: %d nome: %s\n", p->primeiro->info, p->primeiro->nome);
    }
}