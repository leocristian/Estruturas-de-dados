#include<stdio.h>
#include<stdlib.h>
#include"listaEncadeada.h"

int main(int argc, char const *argv[])
{
    No *lista;
    int op, valor;

    lista = criarListaEncadeada();
    printf("1 - Inserir valor no Início\n"
            "2 - Inserir valor no Fim\n"
            "3 - Inserir valor ordenado\n"
            "4 - Remover\n"
            "5 - Buscar\n"
            "6 - Mostrar\n");
    do{
        printf("Escolha a opção: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("---Inserir no Início---\n");
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);

                lista = inserirInicio(lista, valor);break;
            case 2:
                printf("---Inserir no Fim---\n");
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);

                lista = inserirFim(lista, valor);break;
            case 3:
                printf("---Inserir ordenado---\n");
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);

                lista = inserirOrdenado(lista, valor);break;
            case 4:
                printf("---Remover---\n");
                printf("Digite o valor para remover: ");
                scanf("%d", &valor);

                lista = remover(lista, valor);break;
            case 5:
                printf("---Buscar---\n");
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);

                buscar(lista, valor);break;
            case 6:
                printf("---Valores da Lista Encadeada ---\n");
                mostrarLista(lista);break;
        }
    }while(op != 0);

    liberar(lista);
    return 0;
}
