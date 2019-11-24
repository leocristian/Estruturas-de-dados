typedef struct lista Lista;
typedef struct pilha Pilha;

Pilha *criarPilha();
void pushPilha(Pilha *p, int valor);
int popPilha(Pilha *p);
void liberar(Pilha *p);
void liberar(Pilha *p);
void topo(Pilha *p);
