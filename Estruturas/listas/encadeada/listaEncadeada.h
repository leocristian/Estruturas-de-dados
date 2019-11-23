//
//  listaEncadeada.h
//  tad1-1610
//
//  Created by Antonio Oseas on 30/10/19.
//  Copyright © 2019 Antonio Oseas. All rights reserved.
//

#ifndef listaEncadeada_h
#define listaEncadeada_h

typedef struct no No;

No *criarListaEncadeada();
No *inserirInicio(No *lista, int v);
No *inserirFim(No *lista, int v);
No *inserirOrdenado(No *lista, int v);
No *remover(No *lista, int v);
void buscar(No *lista, int v);
void mostrarLista(No *lista);
void liberar(No *lista);
int menu();

#endif /* listaEncadeada_h */
