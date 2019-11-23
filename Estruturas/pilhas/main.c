#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

int main(int argc, char const *argv[])
{
    Pilha *p;
    int op = -1, valor;

    p = criarPilha();

    printf("1 - Push Pilha (Adicionar elemento)\n"
            "2 - Pop Pilha (Remover elemento)\n"
            "3 - Mostrar Pilha\n"
            "4 - Sair\n");

    while(op != 0){
        printf("Escolha a opção: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                puts("-----Adicionar valor-----");
                printf("Valor: ");
                scanf("%d", &valor);

                pushPilha(p, valor);
                break;
            case 2:
                popPilha(p);
                break;
            case 3:
                puts("-----Pilha-----");
                mostrarPilha(p);
                break;
        }
    }
    free(p);
    return 0;
}