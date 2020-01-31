#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"funcoes.h"

int main(){
    srand(time(NULL));

    Imagem *imagem, *resultado;
    int altura, largura, xA, yA, xB, yB;
    int max, min, decimal;
    float distancia;

    printf("Digite a altura e a largura da imagem: ");
    scanf("%d %d", &altura, &largura);

    imagem = gerarImagem(altura, largura);
    int op;
    printf("------Menu Imagem------\n"
            "1 - Maximo Valor.\n"
            "2 - Mínimo Valor.\n"
            "3 - Distãncia euclidiana.\n"
            "4 - Distãncia Manhattan.\n"
            "5 - Calcular LBP (Local Binary Pattern).\n");
    printf("-----------------------\n");
    do{
        printf("Escolha sua opção: ");
        scanf("%d", &op);
        switch(op){
            case 1: 
                max = maximoValor(imagem);
                printf("Maior valor: %d\n", max);break;
            case 2:
                min = minimoValor(imagem);
                printf("Menor valor: %d\n", min);break;
            case 3:
                printf("---Distância Euclidiana---\n");
                printf("Digite o ponto A: ");
                printf("X: ");scanf("%d", &xA);
                printf("Y: ");scanf("%d", &xB);
                printf("Digite o ponto B: ");
                printf("X: ");scanf("%d", &yA);
                printf("Y: ");scanf("%d", &yB);

                distancia = distanciaEuclidiana(xA, xB, yA, yB, imagem);

                printf("Distância: %.1f\n", distancia);break;
            case 4:
                printf("---Distância Manhattan---\n");
                printf("Digite o ponto A: ");
                printf("X: ");scanf("%d", &xA);
                printf("Y: ");scanf("%d", &xB);
                printf("Digite o ponto B: ");
                printf("X: ");scanf("%d", &yA);
                printf("Y: ");scanf("%d", &yB);

                distancia = distanciaManhattan(xA, xB, yA, yB, imagem);

                printf("Distância: %.1f\n", distancia);break;
            case 5:
                resultado = LBP(imagem);
                salvarImagem_txt(resultado, "resultado.txt");
                break;
        }
    }while(op != 0);

    // for (int i = 0; i < altura; i++){
    //     for (int j = 0; j < largura; j++){
    //         printf("%d ", getPixel(imagem, i, j));
    //     }
    //     printf("\n");
    // }

    imagem = liberarImagem(imagem);
    return 0;
}
