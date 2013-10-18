#include <stdio.h>
#include <time.h>
#include <math.h>
#include "matrix.h"

void fractal(matrix_t *M) {
    double CxMin = -2.5;
    double CxMax = 1.5;
    double CyMin = -2.0;
    double CyMax = 2.0;
    double EscapeRadius = 2;
    double ER2 = EscapeRadius*EscapeRadius;
    double PixelWidth = (CxMax - CxMin) / M->cols;
    double PixelHeight = (CyMax - CyMin) / M->rows;
    int IterationMax = 200;
    
    double Zx, Zy;
    double Zx2, Zy2;
    double Cx, Cy;
    int iX = 0;
    int iY = 0;
    int Iteration;    
    
    while (iY < M->rows) {
        Cy = CyMin + iY * PixelHeight;
        if (fabs(Cy) < PixelHeight / 2) Cy = 0.0;
        for (iX = 0; iX < M->cols; iX++) {
            Cx = CxMin + iX * PixelWidth;
            Zx = 0.0;
            Zy = 0.0;
            Zx2 = Zx * Zx;
            Zy2 = Zy * Zy;
            for (Iteration = 0; Iteration < IterationMax && ((Zx2 + Zy2) < ER2); Iteration++) {
                Zy = 2 * Zx * Zy + Cy;
                Zx = Zx2 - Zy2 + Cx;
                Zx2 = Zx * Zx;
                Zy2 = Zy * Zy;
            }
            if (Iteration == IterationMax) {
                M->data[iY][iX] = 1;
            } else {
                M->data[iY][iX] = 0;
            }
        }
        iY++;
    }
}

int main(int argc, char **argv) {
	int n;									// Ordem da imagem.
	matrix_t *M;							// Matriz da imagem.
	struct timeval start_time, end_time;	// Variáveis para coleta do tempo.
    long long total_time;					// Tempo total de execução.
    
    // Validação do argumento.
    if ((argc != 2)) {
        printf("Uso: %s <ordem da imagem>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
	
	// Coleta o argumento.
    n = atoi(argv[1]);

	// Cria a matriz da imagem.
    M = matrix_create(n, n);

    // Captura o tempo inicial.
    gettimeofday(&start_time, NULL);
    
    // Inicia a função para gerar o fractal.
    fractal(M);
    
    // Captura o tempo final e calcula o tempo de execução.
    gettimeofday(&end_time, NULL);
    total_time = ((end_time.tv_sec - start_time.tv_sec) * 1000000LL + end_time.tv_usec - start_time.tv_usec) / 1000;

	// Imprime o cabeçalho do arquivo pbm e a matriz.
	//printf("P1\n #Serial\n %d %d\n", n, n);
    //matrix_print(M);

	// Cria um arquivo e grava o tempo de execução.
    FILE *file = fopen("estatistica.txt", "a+");
    // Ordem da matriz - Tempo de execução - Número de threads
    fprintf(file, "%i %lli 1\n", n, total_time);
    fclose(file);
    fflush(stdout);

	// Limpa a memória.
    matrix_destroy(M);
    
    return EXIT_SUCCESS;
}
