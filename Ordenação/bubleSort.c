#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *bubbleSort(char str[10]){
    int n = strlen(str);

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(str[j] > str[j+1]){
                int aux = str[j];
                str[j] = str[j+1];
                str[j+1] = aux;
            }
        }
    }
    return str;
}
int main(){
    char string[10];
    printf("Digite a string: ");
    scanf("%s", string);

    bubbleSort(string);
    printf("palavra ordenada: %s\n", string);

    return 0;
}