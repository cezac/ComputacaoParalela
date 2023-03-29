#include <stdio.h>
#include <sys/time.h> 
#include <stdlib.h>

#define MAX 1000 /* tamanho máximo das matrizes */
#define BLOCK_SIZE 16 /* tamanho do bloco */

int main()

{
    /* exemplos de tamanhos das matrizes a serem geradas */ 
  
    int tamanhos[] = {32, 64, 128, 256, 512, 640, 768, 896, 1024, 1536};
    int n, i, j, k, ii, jj, kk;
    int **a, **b, **c;

    struct timeval tv;
    double start_t, end_t, tempo_gasto;

    /* aloca espaco para as matrizes a, b e c */
    /* MAX eh inicializado com um dos tamanhos do vetor acima */

    a = (int **) calloc(MAX, sizeof(int *));
    b = (int **) calloc(MAX, sizeof(int *));
    c = (int **) calloc(MAX, sizeof(int *));

    for(i = 0; i < MAX; i++)
    
    {
      
        a[i] = (int *) calloc(MAX, sizeof(int));
        b[i] = (int *) calloc(MAX, sizeof(int));
        c[i] = (int *) calloc(MAX, sizeof(int));
    }

    /* inicializa as matrizes */

    for(i = 0; i < MAX; i++)
    
    {
      
        for(j = 0; j < MAX; j++)
        
        {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
          
        }
      
    }

  
    /* exemplo de como calcular o tempo de execução somente do trecho
    * especifico que faz a operacao com as matrizes 
    */
         
    gettimeofday(&tv, NULL);
    start_t = (double) tv.tv_sec + (double)tv.tv_usec / 1000000.0;

    /* realiza a multiplicação das matrizes */

    for (ii = 0; ii < MAX; ii += BLOCK_SIZE) 
    {
        for (jj = 0; jj < MAX; jj += BLOCK_SIZE) 
        {
            for (kk = 0; kk < MAX; kk += BLOCK_SIZE) 
            {
                for (i = ii; i < ii + BLOCK_SIZE && i < MAX; i++) 
                {
                    for (j = jj; j < jj + BLOCK_SIZE && j < MAX; j++) 
                    {
                        for (k = kk; k < kk + BLOCK_SIZE && k < MAX; k++) 
                        {
                            c[i][j] += a[i][k] * b[k][j];
                        }
                    }
                }
            }
        }
    }

    gettimeofday(&tv,NULL); 
    end_t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
    tempo_gasto = end_t - start_t;
    printf("Tempo de execucao: %f segundos\n", tempo_gasto);

    /* libera a memoria alocada */

    for(i = 0; i < MAX; i++)
    
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
      
    }
  
    free(a);
    free(b);
    free(c);

    return 0;
}
