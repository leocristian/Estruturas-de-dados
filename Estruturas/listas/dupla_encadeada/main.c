#include<stdio.h>
#include<stdlib.h>
#include"dupla.h"

int main(){
    No *lista;
    int op, valor;

    lista = criarLista();

    printf("1 - Inserir Ordenado\n"
            "2 - Remover Elemento\n"
            "3 - Buscar Elemento\n"
            "4 - Mostrar Lista\n"
            "5 - Liberar Lista\n"
            "0 - Sair do Programa\n");
    do{
        printf("Escolha a opção do MENU: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite o valor para inserir: ");
            scanf("%d", &valor);
            lista = inserirOrdenado(lista, valor);
            break;
        
        case 2:
            printf("Digite o valor para remover: ");
            scanf("%d", &valor);
            lista = remover(lista, valor);
            break;
        
        case 3:
            printf("Digite o valor para buscar: ");
            scanf("%d", &valor);
            buscar(lista, valor);
            break;
        
        case 4:
            mostrarLista(lista);
            break;
        }

    }while(op != 0);

    liberar(lista);

    return 0;
}