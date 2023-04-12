
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
clock_t começo;
clock_t final;

// Estrutura que armazena os dados para cada thread
typedef struct
{
    int* linha;
    int linhas;
    int colunas;
    int thread;
} dados_thread;

// Função executada por cada thread
void alocaLinha(dados_thread * dados)
{
    for (int i = 0; i < dados->linhas; i++)
        dados->linha[i] = dados->thread * dados->colunas + i;
}

// Função que cria uma matriz de tamanho linhas x colunas
int ** criaMatriz(int linhas, int colunas)
{
    começo = clock();
    // Aloca um vetor de ponteiros
    int ** matriz = (int **) malloc(linhas * sizeof(int *));

    // Aloca cada linha da matriz como um vetor de threads
    pthread_t * threads = (pthread_t *) malloc( linhas * sizeof(pthread_t) );
    dados_thread * dados = (dados_thread *) malloc( linhas * sizeof(dados_thread) );

    // Executa a thread para cada linha da matriz
    for (int i = 0; i < linhas; i++)
    {
        dados[i].linha = (int *) malloc(colunas * sizeof(int));
        dados[i].linhas = linhas;
        dados[i].colunas = colunas;
        dados[i].thread = i;
        pthread_create(&threads[i], NULL, (void *) alocaLinha, &dados[i]);
    }

    // Espera a execução das threads
    for (int i = 0; i < linhas; i++)
    {
        pthread_join(threads[i], NULL);
        matriz[i] = dados[i].linha;
    }
    final = clock();
    // Exibi o tempo de processamento para criação da matriz
    printf ("Tempo de processamento: %f", ((float)começo - final) / ((CLOCKS_PER_SEC)));

    free(threads);
    free(dados);

    // Retorna a matriz alocada
    return matriz;
}

// Função para exibir a matriz
void printaMatriz(int ** matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

// Função que multiplica a matriz pelo vetor
int multiplicaMatrizVetor(int ** matriz, int * vetor, int linhas, int colunas, int *resultado)
{
    começo = clock();
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
            resultado[i] += matriz[i][j] * vetor[j];
    }
     
    final = clock();
    printf ("Tempo de processamento2 : %f", ((float)começo - final) / ((CLOCKS_PER_SEC)));
    return resultado;
    printf("%d ", resultado);
}

int main()
{
    // Declara a matriz e define o seu tamanho
    int ** matriz;
    int* resultado;
    int* vetor = {2,2,2};
    int linhas = 3, colunas = 3;

    // Cria a matriz
    matriz = criaMatriz(linhas, colunas);

    // exibi a matriz
    printaMatriz(matriz, linhas, colunas);

    //multiplica por um vetor
    multiplicaMatrizVetor(matriz, vetor, linhas, colunas, resultado);

    // Libera a memória alocada
    for (int i = 0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);

    return 0;
}
