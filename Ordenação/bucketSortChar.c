#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 5

struct bucket{
  int quantidade;
  char valores[TAM];
};

typedef struct bucket Bucket;

void selection(char *num, int tam){ 
  int i, j, min, aux, cont=0;
  for (i = 0; i < (tam-1); i++){
    min = i;
    for (j = (i+1); j < tam; j++) {
      cont++;
      if(num[j] < num[min]) 
      min = j;
    }
    if (num[i] != num[min]){
      aux = num[i];
      num[i] = num[min];
      num[min] = aux;
    }
  }
}

void bucket(char *vetor, int tamanho){
  int maior, menor, nBuckets, p;
  Bucket *baldes;
  maior = menor = vetor[0];
  for(int i = 1; i < tamanho; i++){
    if(vetor[i] > maior)
      maior = vetor[i];
    if(vetor[i] < menor)
      menor = vetor[i];
  }
  nBuckets = ((maior - menor)/TAM)+1;
  printf("Quantidade de buckets: %d\n", nBuckets);
  baldes = (Bucket *)malloc(sizeof(Bucket) * nBuckets);

  for (int i = 0; i < nBuckets; i++){
    baldes[i].quantidade = 0;
  }

  for (int i = 0; i < tamanho; i++){
    p = (vetor[i] - menor)/TAM;
    baldes[p].valores[baldes[p].quantidade] = vetor[i];
    baldes[p].quantidade++;
  }
  p = 0;
  for (int i = 0; i < nBuckets; i++){
    selection(baldes[i].valores, baldes[i].quantidade);
    for (int j = 0; j < baldes[i].quantidade; j++){
      vetor[p] = baldes[i].valores[j];
      p++;
    }
  }
  for (int i = 0; i < nBuckets; i++){
    printf("Bucket %d: ", i);
    for (int j = 0; j < baldes[i].quantidade; j++){
      printf("%c ", baldes[i].valores[j]);
    }
    printf("\n");
  }
  free(baldes);
}
int main(){
  char str[30];

  printf("Digite a palavra: ");
  scanf("%s", str);
  printf("vetor desordenado: ");
  printf("\n\n");
  bucket(str, strlen(str));
  printf("\nvetor ordenado: ");
  printf("%s\n", str);
}
