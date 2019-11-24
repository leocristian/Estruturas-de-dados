#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

int main(int argc, char const *argv[])
{
    int valor, op = -1;
    Pilha *p;

    p = criarPilha();
    while(op != 0){
        printf("Opção: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                scanf("%d", &valor);
                pushPilha(p, valor);
                break;
            case 2:
                valor = popPilha(p);
                printf("Valor removido: %d\n", valor);
                break;
            case 3:
                topo(p);
        }
    }
    liberar(p);
    return 0;
}
