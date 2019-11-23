#include<stdio.h>
#include<stdlib.h>
#include"listaEstatica.h"

int *criarLista(){
    int *lista;

    lista = (int *)malloc(sizeof(int) * tam);

    return lista;
}

int *inserirFim(int *lista, int *p,int valor){
    if (lista == NULL){
        lista = (int *) malloc(sizeof(int)*tam);
        printf("Lista alocada\n");
    }
    if(*p < tam){
        lista[*p] = valor;
    }
    (*p)++;

    return lista;
}

int *inserirInicio(int *lista, int *p, int valor){
    (*p)++;
    for (int i = *p; i >= 0 ; i--){
        lista[i] = lista[i-1];
    }
    lista[0] = valor;

    return lista;
}
int *inserirOrdenado(int *lista, int *p, int valor){
    int i=0;
    for (i = 0; i < *p; i++){
        if(lista[i] >= valor){
            for (int j = (*p)-1; j >= 0; j--){
                lista[j+1] = lista[j];
            }
            lista[i] = valor;
        }
        break;
    }
    if(i == *p){
        lista[i] = valor;
    }
    (*p)++;
    return lista;
}
void remover(int *lista, int *p, int valor){
    for (int i = 0; i < *p; i++){
        if(lista[i] == valor){
            lista[i] = lista[(*p)-1];
            (*p)--;
        }
    }
    printf("Valor %d removido da lista\n", valor);
}
int buscar(int *lista, int *p, int valor){
    for (int i = 0; i < *p; i++){
        if(lista[i] == valor){
            return i;
        }
    }
    return 0;
}
void tamanho(int *p){
    printf("Tamanho da lista: %d\n", *p);
}
void mostrar(int *lista, int *p){
    printf("---Lista---\n");
    for (int i = 0; i < *p; i++){
        printf("%d\n", lista[i]);
    }
}