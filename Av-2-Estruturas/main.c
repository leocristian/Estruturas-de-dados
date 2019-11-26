#include"batalha.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int op = -1, forca;
    float altura, peso;
    char nome[50];
    Fila *lutadores;
    Pilha *perdedores;
    Lutador *vencedor;

    lutadores = criarFila();
    perdedores = criarPilha();

    while(op != 0){
        printf("1 - Inserir Lutador\n2 - Batalhar\n3 - mostrarPerdedores\n4 - Mostrar Lutadores\n");
        printf("Escolha a opcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Nome do lutador: ");
                setbuf(stdin, NULL);
                scanf("%s", nome);
                altura = rand()%100/10.0;
                peso = rand()%100/10.0;
                inserirLutador(lutadores, nome, altura, peso);
                calcularForcas(lutadores);
                break;
            case 2:
                realizarLuta(lutadores, perdedores);
                break;

            case 3:
                mostrarPerdedores(perdedores);
                break;
            case 4:
                mostrarLutadores(lutadores);
                break;
        }
    }

    liberar(lutadores);
    return 0;
}
