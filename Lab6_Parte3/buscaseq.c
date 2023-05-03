#include "stdio.h"
#include "stdlib.h"

int* guarda_Vetor (FILE *arquivo, int tamanho) // Função para armazenar os elementos do txt dentro do vetor
{
    int *vetor = malloc(sizeof(int) * tamanho);
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
    return vetor;
}

void ordena_Vetor(int *vetor, int tamanho) // Função que ira ordenar o vetor
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
}

int buscaBinaria(int *vetor, int elemento, int tamanho) //Defina uma função de busca binária que recebe dois parâmetros: um vetor de inteiros e o elemento que se deseja encontrar
{
    //Declare variáveis inteiras min e max
    int min = 0;
    int max = tamanho - 1;

    //Enquanto min é menor ou igual a max
    while (min <= max) {
        //Encontre o meio do vetor
        int meio = (min + max) / 2;

        //Se o elemento no meio do vetor for igual ao elemento procurado
        if (vetor[meio] == elemento) {
            //Retorne a posição do elemento
            return meio;
        }
            //Se o elemento no meio do vetor for menor que o elemento procurado
        else if(vetor[meio] < elemento) {
            min = meio + 1;
        }
            //Se o elemento no meio do vetor for maior que o elemento procurado
        else {
            max = meio - 1;
        }
    }
    return -1;
}

int main()
{
    FILE *arquivo; // Variavel do tipo ponteiro para FILE
    char nome_arquivo[10]; //Vetor de char para guardar o nome do arquivo
    int elemento = 0;
    int tamanho = 65536;

    printf("Digite o nome do arquivo: "); // Lê o nome do arquivo na linha de comando
    scanf("%s", *&nome_arquivo);

    arquivo = fopen(nome_arquivo, "r"); // Abertura do txt

    int *vetor = guarda_Vetor(arquivo, tamanho); // Chamada da função que guarda o elementos no vetor
    ordena_Vetor(vetor, tamanho); // Chamada da função que ira ordenar o vetor
    for (int i=0; i<tamanho; i++){ // Printa o vetor ordenado
        printf("%d, \n", vetor[i]);
    }
    printf("Digite o elemento que deseja encontrar: "); // Lê o elememto que deseja encontarar na linha de comando
    scanf("%d", &elemento);
    int posicao = buscaBinaria(vetor, elemento, tamanho); // Chama da funcao que ira encontrar o elemento no vetor
    printf("A posicao do elemento %d = %d\n", elemento, posicao);
    return 0;
}
