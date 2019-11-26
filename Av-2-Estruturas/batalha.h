typedef struct lutador Lutador;
typedef struct fila Fila;
typedef struct pilha Pilha;

void inserirLutador(Fila *lutadores, char nome[], float altura, float peso);
Fila *criarFila();
Pilha *criarPilha();
void mostrarLutadores(Fila *lutadores);
void calcularForcas(Fila *lutadores);
void mostrarLutadores(Fila *lutadores);
void mostrarPerdedores(Pilha *perdedores);
void realizarLuta(Fila *lutadores, Pilha *perdedores);
void liberar(Fila *lutadores);
