typedef struct pessoa Pessoa;
typedef struct docente Docente;
typedef struct discente Discente;

Docente *alocarDocente(int quantidade);
Docente *cadastrarDocente(Docente *d, int *quantidade);
void removerDocente(Docente *d, int *quantidade);
void alterarDocente(Docente *d, int quantidade);
void buscarDocente(Docente *d1, Discente **d2, int quantidade1, int quantidade2);
void mostrarDocente(Docente *d, int quantidade);

Discente **alocarDiscente(int quantidade1, int quantidade2);
Discente **cadastrarDiscente(Docente *d1, Discente **d2, int *qtd1, int qtd2);
void removerDiscente(Discente *d, int *quantidade);
void alterarDiscente(Discente *d, int quantidade);
void buscarDiscente(Discente *d, int quantidade);
void mostrarDiscente(Discente **d1, Docente *d2, int quantidade1, int quantiadade2);
void liberarDiscente(Discente **d, int quantidade);