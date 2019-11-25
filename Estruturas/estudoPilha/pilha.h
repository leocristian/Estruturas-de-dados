typedef struct no No;
typedef struct pilha Pilha;

Pilha *criarPilha();
void mostrar(Pilha *p);
void inserirPilha(Pilha *p, int valor, char nome[]);
void removerPilha(Pilha *p);
void liberar(Pilha *p);