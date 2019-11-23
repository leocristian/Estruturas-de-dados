typedef struct pilha Pilha;
Pilha *criarPilha(void);
void pushPilha(Pilha *p, int v);
void popPilha(Pilha *p);
void mostrarPilha(Pilha *p);
void liberaPilha(Pilha *p);