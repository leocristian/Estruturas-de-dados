#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

int main(int argc, char const *argv[]){

    Pilha *p;
    int op = -1, valor;
    char nome[10];

    p = criarPilha();

    printf("1 - Inserir dados na pilha\n2 - Remover\n3 - Mostrar\n");
    while(op != 0){
        printf("Escolha a opção: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Idade: ");
                scanf("%d", &valor);
                printf("Nome: ");
                setbuf(stdin, NULL);
                scanf("%s", nome);
                inserirPilha(p, valor, nome);
                break;
            case 2:
                removerPilha(p);
                break;
            case 3:
                mostrar(p);
                break;
        }
    }
    liberar(p);
}
