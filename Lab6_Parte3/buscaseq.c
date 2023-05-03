#include "stdio.h"
#include "stdlib.h"
FILE *arquivo;

int guarda_Vetor (FILE *arquivo)
{
    int vetor[65536];
    int aux;
    int interator = 0;

    if (arquivo==NULL){
        printf("Erro ao encontrar o arquivo\n");
        exit(1);
    }
    while(fscanf(arquivo, "%d", &aux)!=EOF) {
        if (aux !='\n') {
            vetor[interator] = aux;
            printf("%d", vetor[interator]);
            interator++;
        }
    }
    return vetor;
}

int busca_Binaria (int vector[], int elem, int tamanho)
{
    int comeco = 0;
    int final = tamanho-1;
    while(comeco<=final){
        int i = (comeco+final)/2;
        if (vector[i]==elem){
            return vector[i];
        }
        if (vector[i]<elem){
            comeco = i+1;
        }
        else{
            final = i;
        }
    }
    return -1;
}


int main() {

    arquivo = fopen("vetor1.txt","r");
    guarda_Vetor(arquivo);
    

    return 0;
}
