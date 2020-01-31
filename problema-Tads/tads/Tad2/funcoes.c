#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"funcoes.h"

struct pixel {
    int x, y, valor_pixel;
};
struct imagem {
    int altura, largura;
    Pixel *pixels_imagem;//variar de 0 ate 255
};

Imagem *criarImagem(int altura, int largura){
    Imagem *img;

    img = (Imagem *)calloc(1,sizeof(Imagem));
    img->altura = altura;
    img->largura = largura;
    img->pixels_imagem = (Pixel *)calloc(sizeof(Pixel), (altura * largura));

    return img;
}

void setPixel(Imagem *img, int i, int j, int valor){
    img->pixels_imagem[i*img->largura+j].valor_pixel = valor;
}
int getPixel(Imagem *img, int i, int j){
    return img->pixels_imagem[i*img->largura+j].valor_pixel;
}

Imagem *gerarImagem(int altura, int largura){
    Imagem *img = criarImagem(altura,largura);
    int mat[altura][largura];
    char nome_arquivo[10];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    FILE *fptr;

    img->altura = altura;
    img->largura = largura;

    for (int i = 0; i < altura; i++){
        for (int j = 0; j < largura; j++){
            img->pixels_imagem[i*largura+j].valor_pixel = rand()%256;
            img->pixels_imagem[i*largura+j].x = i;
            img->pixels_imagem[i*largura+j].y = j;
        }
    }
    if((fptr = fopen(nome_arquivo, "w")) == NULL){
        printf("Arquivo não pode ser aberto.\n");
    }else{
        fprintf(fptr, "%d %d\n", img->altura, img->largura);
        for (int i = 0; i < img->altura; i++){
            for (int j = 0; j < img->largura; j++){
                fprintf(fptr, "%d ", img->pixels_imagem[i*largura+j].valor_pixel);
            }
            fprintf(fptr, "\n");
        }
        printf("Imagem salva no arquivo: (%s).\n", nome_arquivo);
    }

    fclose(fptr);
    return img;
}
void salvarImagem_txt(Imagem *img, char *nome_arquivo){
    FILE *fptr;

    if((fptr = fopen(nome_arquivo, "w")) == NULL){
        printf("Arquivo não pode ser aberto.\n");
    }else{
        fprintf(fptr, "%d %d\n", img->altura, img->largura);
        for (int i = 0; i < img->altura; i++){
            for (int j = 0; j < img->largura; j++){
                fprintf(fptr, "%d ", getPixel(img, i, j));
            }
            fprintf(fptr, "\n");
        }
        printf("Imagem salva no arquivo: (%s).\n", nome_arquivo);
    }

    fclose(fptr);
}
Imagem *liberarImagem(Imagem *img){
    free(img->pixels_imagem);
    free(img);
    img = NULL;
    return img;
}

int maximoValor(Imagem *img){
    int max = img->pixels_imagem[0].valor_pixel;

    for (int i = 0; i < img->altura; i++){
        for (int j = 0; j < img->largura; j++){
            if(img->pixels_imagem[i*img->largura+j].valor_pixel > max){
                max = img->pixels_imagem[i*img->largura+j].valor_pixel;
            }
        }
    }
    return max;
}
int minimoValor(Imagem *img){
    int min = img->pixels_imagem[0].valor_pixel;

    for (int i = 0; i < img->altura; i++){
        for (int j = 0; j < img->largura; j++){
            if(img->pixels_imagem[i*img->largura+j].valor_pixel < min){
                min = img->pixels_imagem[i*img->largura+j].valor_pixel;
            }
        }
    }
    return min;
}
float distanciaEuclidiana(int xA, int xB, int yA, int yB, Imagem *img){
    float dis;
    Pixel pontoA, pontoB;

    pontoA.x = xA;
    pontoA.y = yA;
    pontoB.x = xB;
    pontoB.y = yB;

    int valor_A = img->pixels_imagem[xA * img->largura + xB].valor_pixel;
    int valor_B = img->pixels_imagem[yA * img->largura + yB].valor_pixel;

    printf("Valor pos A: %d\n", valor_A);
    printf("Valor pos B: %d\n", valor_B);

    dis = sqrt(pow((pontoA.y - pontoA.x), 2) + pow((pontoB.y - pontoB.x), 2));

    return dis;
}
float distanciaManhattan(int xA, int xB, int yA, int yB, Imagem *img){
    float dis;
    Pixel pontoA, pontoB;

    pontoA.x = xA;
    pontoA.y = yA;
    pontoB.x = xB;
    pontoB.y = yB;

    int valor_A = img->pixels_imagem[xA * img->largura + xB].valor_pixel;
    int valor_B = img->pixels_imagem[yA * img->largura + yB].valor_pixel;

    printf("Valor pos A: %d\n", valor_A);
    printf("Valor pos B: %d\n", valor_B);

    dis = ((pontoA.y - pontoA.x) + (pontoB.y - pontoB.x));

    dis = abs(dis);

    return dis;
}
Imagem *LBP(Imagem *img){
    printf("%d %d\n", img->altura, img->largura);
    Imagem *resultado = criarImagem(img->altura, img->largura);

    int vizinhos[8][2] = {{-1,-1}, {-1,0}, {-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    int soma = 0;
    for (int i = 1; i < img->altura-1; i++){
        for (int j = 1; j < img->largura-1; j++){
            soma = 0;
            for (int k = 0; k < 8; k++){
                soma += pow(2*(getPixel(img, i+vizinhos[k][0], j+vizinhos[k][1]) >= getPixel(img, i, j)),7-k);
            }
            setPixel(resultado, i, j, soma);
        }
    }
    return resultado;
}