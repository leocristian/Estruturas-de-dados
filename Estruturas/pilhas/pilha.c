#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

#define tam 50

struct pilha{
    int n;
    int vet[tam];
};

Pilha *criarPilha(void){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}
void pushPilha(Pilha *p, int v){
    if(p->n == tam){
        printf("Capacidade Máxima da pilha.\n");
    }else{
        p->vet[p->n] = v;
        p->n++;
    }
}
void popPilha(Pilha *p){
    if(p->n == 0){
        puts("Pilha vazia.");
    }else{
        printf("Valor removido: %d\n", p->vet[p->n-1]);
        p->n--;
    }
}
void mostrarPilha(Pilha *p){
    for (int i = p->n-1; i >= 0; i--){
        printf("%d\n", p->vet[i]);
    }
}
void liberaPilha(Pilha *p){
    free(p);
}