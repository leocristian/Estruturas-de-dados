#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"

struct pessoa{
    char *nome;
    int idade, ID;//identificador
    int matricula;//deve ser gerada automaticamente
};
struct docente{
    Pessoa info_docente;
    int qtd_orientacoes_graduacao, qtd_orientacoes_pos_graduacao; 
};
struct discente{
    Pessoa info_discente;
    int nivel;// 1- graduacao ou 2 - posgraduacao
    char *nome_curso;
    int senha, ID_orientador, ID_coorientador;
};

Docente *alocarDocente(int qtd_docente){
    Docente *d; 
    d = (Docente *)malloc(sizeof(Docente)*qtd_docente);

    return d;
}
Docente *cadastrarDocente(Docente *docente, int *qtd_docente){
    docente = (Docente *) realloc(docente, sizeof(Docente) * ((*qtd_docente) + 1));

    printf("---------Cadastro de DOCENTE---------\n");
    printf("Nome: ");
    docente[*qtd_docente].info_docente.nome = (char *)malloc(sizeof(char) * 50);
    scanf(" %[^\n]s", docente[*qtd_docente].info_docente.nome);
    printf("Idade: ");
    setbuf(stdin, NULL);
    scanf(" %d", &docente[*qtd_docente].info_docente.idade);
    docente[*qtd_docente].info_docente.ID = *qtd_docente + 1;
    printf("ID: %d\n", docente[*qtd_docente].info_docente.ID);
    docente[*qtd_docente].info_docente.matricula = 1 + rand()%1000;
    printf("Matrícula (Gerada automaticamente): %d\n", docente[*qtd_docente].info_docente.matricula);
    (*qtd_docente)++;
    setbuf(stdin, NULL);

    return docente;
}
// A função remover troca a chave achada com a ultima poisção do vetor e depois diminui o tamanho do vetor
void removerDocente(Docente *docente, int *qtd_docente){
    int chave;

    printf("-------Remover DOCENTE-------\n");
    printf("Digite o id para remover: ");
    scanf("%d", &chave);

    for (int i = 0; i < *qtd_docente; i++){
        if(chave == docente[i].info_docente.ID){
            docente[i] = docente[(*qtd_docente) - 1];
            (*qtd_docente)--;
        }
    }
    printf("Docente de ID %d foi removido!\n", chave);
}
void alterarDocente(Docente *docente, int qtd_docente){
    int chave;

    printf("-------Alterar DOCENTE-------\n");
    printf("Digite o id para alterar os dados do docente: ");
    scanf("%d", &chave);

    // Sobreescreve a posição com os dados corretos de um novo docente
    for (int i = 0; i < qtd_docente; i++){
        if(chave == docente[i].info_docente.ID){
            printf("Nome: ");
            scanf(" %[^\n]s", docente[i].info_docente.nome);
            printf("Idade: ");
            setbuf(stdin, NULL);
            scanf(" %d", &docente[i].info_docente.idade);
            printf("ID: ");
            setbuf(stdin, NULL);
            scanf(" %d", &docente[i].info_docente.ID);
            docente[i].info_docente.matricula = 1 + rand()%1000;
            printf("Matrícula (Gerada automaticamente): %d\n", docente[i].info_docente.matricula);
        }
    }
    printf("Docente de ID %d foi alterado.\n", chave);
}
void buscarDocente(Docente *docente, Discente **discente, int qtd_docente, int qtd_discente){
    int id, pos;
    mostrarDocente(docente, qtd_docente);
    printf("Digite o id do docente para buscar: ");
    scanf("%d", &id);
    if(docente[id].qtd_orientacoes_graduacao + docente[id].qtd_orientacoes_pos_graduacao == 0){
        printf("Orientador não possui orientandos cadastrados.\n");
    }else{
        for (int i = 1; i <= qtd_docente; i++){
            if(docente[i].info_docente.ID == id){
                printf("ID: %d\t", docente[i].info_docente.ID);
                printf("Nome: %s\t", docente[i].info_docente.nome);
                printf("\nLista de alunos orientados pelo prof. %s\n", docente[i].info_docente.nome);
                mostrarDiscente(discente, docente, qtd_docente, qtd_discente);
            }
        }
    }
}
void mostrarDocente(Docente *docente, int qtd_docente){
    printf("---------Lista de DOCENTES---------\n");
    for (int i = 0; i < qtd_docente; i++){
        printf("ID: %d---Nome: %s\n", docente[i].info_docente.ID, docente[i].info_docente.nome);
    }
    printf("-----------------------------------\n");
}

Discente **alocarDiscente(int qtd_docente, int qtd_discente){
    Discente **d;

    d = (Discente **)calloc(sizeof(Discente *), qtd_docente);

    for (int i = 0; i < qtd_docente; i++){
        d[i] = (Discente *)calloc(sizeof(Discente), qtd_discente);
    }
    return d;
}

Discente **cadastrarDiscente(Docente *docente, Discente **discente, int *qtd_discente, int qtd_docente){
    //discente = (Discente *) realloc(discente, sizeof(Discente) * ((*qtd_discente) + 1));
    discente = alocarDiscente(qtd_docente, 5);
    int id_orientador;

    if(qtd_docente == 0 ){
        printf("Ainda não temos orientadores cadastrados.\n");
    }else{
        mostrarDocente(docente, qtd_docente);
        printf("Escolha seu orientador pelo ID: ");
        
        scanf("%d", &id_orientador);
        for (int i = 0; i < qtd_docente; i++){
            if(docente[i].info_docente.ID == id_orientador){
                discente[i][*qtd_discente].ID_orientador = docente[i].info_docente.ID;
            }
        }
    }
    printf("Nome: ");
    discente[id_orientador][*qtd_discente].info_discente.nome = (char *) malloc(sizeof(char) * 50);
    scanf(" %[^\n]s", discente[id_orientador][*qtd_discente].info_discente.nome);
    printf("Idade: ");
    setbuf(stdin, NULL);
    scanf(" %d", &discente[id_orientador][*qtd_discente].info_discente.idade);
    discente[id_orientador][*qtd_discente].info_discente.ID = (*qtd_discente);
    printf("ID: %d\n", discente[id_orientador][*qtd_discente].info_discente.ID);
    discente[id_orientador][*qtd_discente].info_discente.matricula = 1 + rand()%1000;
    printf("Matrícula (Gerada automaticamente): %d\n", discente[id_orientador][*qtd_discente].info_discente.matricula);
    printf("1 - Graduação\n2 - Pós Graduação\n");
    printf("Escolha seu nível: ");
    do{
        scanf("%d", &discente[id_orientador][*qtd_discente].nivel);
        if(discente[id_orientador][*qtd_discente].nivel == 1){
            docente[qtd_docente].qtd_orientacoes_graduacao++;
            break;
        }else if(discente[id_orientador][*qtd_discente].nivel == 2){
            docente[qtd_docente].qtd_orientacoes_pos_graduacao++;
            break;
        }else{
            printf("Opção inválida");
        }
    }while(discente[id_orientador][*qtd_discente].nivel != 1 || discente[id_orientador][*qtd_discente].nivel != 2);

    (*qtd_discente)++;
    setbuf(stdin, NULL);

    return discente;
}
//void login(){

//}

//void removerDiscente(Discente discente){

// }
// void alterarDiscente(Discente discente){

// }
// void buscarDiscente(Discente discente){

// }

void mostrarDiscente(Discente **discente, Docente *docente, int qtd_docente, int qtd_discente){
    
    printf("---------Lista de DISCENTES---------\n");
    for (int i = 0; i < qtd_docente; i++){
        for (int j = 0; j < qtd_discente; j++){
            if(discente[i][j].ID_orientador == docente[i].info_docente.ID){
                printf("ID: %d---Nome: %s---ID Orientador: ", discente[i][j].info_discente.ID, discente[i][j].info_discente.nome);
                printf("%d\n", discente[i][j].ID_orientador);
            }
        }
    }
    printf("-----------------------------------\n");
}

void liberarDiscente(Discente **d, int qtd_docente){
    for (int i = 0; i < qtd_docente; i++){
        free(d[i]);
    }
    free(d);
}