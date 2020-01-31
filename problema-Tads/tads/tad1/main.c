#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"

int quantidade_docentes = 0, quantidade_discentes = 0;

int main(int argc, char const *argv[])
{
    Docente *orientador = NULL;
    orientador = alocarDocente(quantidade_docentes);
    Discente **orientando = NULL;
    orientando = alocarDiscente(quantidade_docentes, quantidade_discentes);
    int op = -1;

    printf( "----Controle dos Docentes----\n");
    printf( "1 - Cadastrar Docente.\n"
            "10 - Cadastrar Discente\n"
            "2 - Remover docente.\n"
            "3 - Alterar docente.\n"
            "4 - Buscar docente.\n"
            "5 - Mostrar Docentes.\n"
            "0 - Finalizar.\n");
    printf("----------------------------\n");

    while(op != 0){
        printf("Escolha a opção do menu principal: ");
        scanf("%d", &op);
        switch(op){
            case 0:
                return 0;break;
            case 1:
                orientador = cadastrarDocente(orientador, &quantidade_docentes);
                printf("Quantidade: %d\n", quantidade_docentes);break;
            case 10:
                orientando = cadastrarDiscente(orientador, orientando, &quantidade_discentes, quantidade_docentes);
                break;
            case 2:
                removerDocente(orientador, &quantidade_docentes);break;
            case 3:
                alterarDocente(orientador, quantidade_docentes);break;
            case 4:
                buscarDocente(orientador, orientando, quantidade_docentes, quantidade_discentes);break;
            case 5:
                mostrarDocente(orientador, quantidade_docentes);break;
        }
    }
    free(orientador);
    liberarDiscente(orientando, quantidade_docentes);
}
