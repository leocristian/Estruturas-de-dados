#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

int main(int argc, char const *argv[]){

    Fila *f;
    int op = -1, valor;
    char nome[10];

    f = criarFila();

    printf("1 - Inserir dados na fila\n2 - Remover\n3 - Mostrar\n");
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
                inserirFila(f, valor, nome);
                break;
            case 2:
                removerFila(f);
                break;
            case 3:
                mostrar(f);
                break;
        }
    }
    liberar(f);
}
