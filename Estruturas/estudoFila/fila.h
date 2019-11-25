typedef struct no No;
typedef struct fila Fila;

Fila *criarFila();
void inserirFila(Fila *f, int valor, char nome[]);
void removerFila(Fila *f);
void mostrar(Fila *f);
void liberar(Fila *f);