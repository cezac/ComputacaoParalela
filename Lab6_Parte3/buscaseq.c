#include "stdio.h"
#include "stdlib.h"

int *guarda_Vetor (FILE *arquivo) // Função para armazenar os elementos do txt dentro do vetor
{
    int vetor[65536]; // Tamanho fixo do vetor 2^16
    int aux;
    int interator = 0;

    if (arquivo==NULL){ // Valida se o arquivo foi encontrado
        printf("Erro ao encontrar o arquivo\n");
        exit(1);
    }
    while(fscanf(arquivo, "%d", &aux)!=EOF) {
        if (aux !='\n') { // Elimina o pulo de linha como um elemento do txt a ser inserido no vetor
            vetor[interator] = aux;
            interator++;
        }
    }
    return *vetor;
}

int *ordena_Vetor(int vetor[], int tamanho) // Função que ira ordenar o vetor
{
    int aux;
    for (int i=0; i < tamanho-1; i++)
    {
        for (int j=0; j < tamanho-i-1; j++)
        {
            if (vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    return *vetor;
}


int main()
{
    FILE *arquivo; // Variavel do tipo ponteiro para FILE
    char nome_arquivo[10]; //Vetor de char para guardar o nome do arquivo
    int *vetor = malloc(sizeof(int) * 65536);

    printf("Digite o nome do arquivo: "); // Lê o nome do arquivo na linha de comando
    scanf("%s", *&nome_arquivo);


    arquivo = fopen(nome_arquivo, "r"); // Abertura do txt

    vetor = guarda_Vetor(arquivo); // Chamada da função que guarda o elementos no vetor
    ordena_Vetor(vetor, 65536); // Chama da função que ira ordenar o vetor

    return 0;
}
