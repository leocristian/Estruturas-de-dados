#include<stdio.h>
#include<stdlib.h>
#include"listaEstatica.h"

int main(){
    int *lista = NULL, p = 0, pos, valor;
    int op;

    lista = criarLista();

    printf("1 - Inserir no início\n2 - Inserir no final\n3 - Inserir Ordenado\n"
           "4 - Remover\n5 - Buscar\n6 - Mostrar\n7 - Tamanho\n");
    do{
        printf("Escolha a opção: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);
                lista = inserirInicio(lista, &p, valor);break;
            case 2:
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);
                lista = inserirFim(lista, &p, valor);break;
            case 3:
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);
                lista = inserirOrdenado(lista, &p, valor);break;
            case 4:
                printf("Digite o valor para remover: ");
                scanf("%d", &valor);
                remover(lista, &p, valor);break;
            case 5:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                pos = buscar(lista, &p, valor);
                printf("Posição do valor %d na lista: %d\n", valor, pos);break;
            case 6:
                mostrar(lista, &p);break;
            case 7:
                tamanho(&p);break;
        }
    }while(op != 0);

    free(lista);
}