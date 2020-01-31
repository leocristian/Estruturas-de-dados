typedef struct pixel Pixel;
typedef struct imagem Imagem;

Imagem *criarImagem(int altura, int largura);
Imagem *gerarImagem(int altura, int largura);
void setPixel(Imagem *img, int i, int j, int valor);
int getPixel(Imagem *img, int i, int j);
Imagem *liberarImagem(Imagem *img);
int maximoValor(Imagem *img);
int minimoValor(Imagem *img);
float distanciaEuclidiana(int xA, int xB, int yA, int yB, Imagem *img);
float distanciaManhattan(int xA, int xB, int yA, int yB, Imagem *img);
int binarioKernel(Imagem *img);
Imagem *LBP(Imagem *img);
void salvarImagem_txt(Imagem *img, char *nome_arquivo);