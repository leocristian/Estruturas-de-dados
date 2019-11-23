//
//  listaEstatica.h
//  tad1-1610
//
//  Created by Antonio Oseas on 29/10/19.
//  Copyright © 2019 Antonio Oseas. All rights reserved.
//

#ifndef listaEstatica_h
#define listaEstatica_h

#define tam 1000
enum opcoes_menu{
    _sair = 0,
    _inserirFim,
    _remover,
    _buscar,
    _mostrar,
    _tamanho
};
int *criarLista();
int *inserirFim(int *lista, int *p, int valor); // op 1
int *inserirInicio(int *lista, int *p, int valor);// op 2
int *inserirOrdenado(int *lista, int *p, int valor);// op 3
void remover(int *lista, int *p, int valor);// op 4
int buscar(int *lista, int *p, int valor);// op 5
void mostrar(int *lista, int *p);// op 6
void tamanho(int *p);// op 7
int menu();
#endif /* listaEstatica_h */
