#include<stdio.h>
#include<stdlib.h>

// Reduz o problema original em subproblemas que possam
// ser resolvidos mais fácil e rápido
void quick(int vet[], int ini, int fim);

int main(){
    int vet[11] = {3, 4, 5, 7, 6, 1, 9, 2, 8, 0};
    int i;

    printf("Vetor desordenado: ");
    for(i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    }
    
    quick(vet, 0, 10); 

    printf("\nVetor ordenado: ");
    for (i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    }
}

void quick(int vet[], int ini, int fim){
    int i, j, pivo, aux;

    i = ini;
    j = fim-1;
    pivo = vet[(ini + fim) / 2];

    while(i < j){
        while(vet[i] < pivo && i < fim){
            i++;
        }
        while(vet[j] > pivo && j > ini){
            j--;
        }
        if(i < j){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }
    if(j > ini){
        quick(vet, ini, j+1);
    }
    if(i < fim){
        quick(vet, i, fim);
    }
}