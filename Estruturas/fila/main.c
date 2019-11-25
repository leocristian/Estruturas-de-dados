#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

int main(int argc, char const *argv[])
{
    int valor, op = -1;
    Fila *f;

    f = criarFila();
    while(op != 0){
        printf("Opção: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                scanf("%d", &valor);
                inserirFila(f, valor);
                break;
            case 2:
                removerFila(f);
                break;
            case 3:
                mostrar(f);
        }
    }

    liberarFila(f);
    return 0;
}