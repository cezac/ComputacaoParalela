#include "stdio.h"
#include "math.h"

int busca_Binaria (int vector[], int elem, int tamanho)
{
    int comeco = 0;
    int final = tamanho-1;
    while(comeco<=final)
    {
        int i = (comeco+final)/2;
        if (vector[i]==elem)
        {
            return vector[i];
        }
        if (vector[i]<elem)
        {
            comeco = i+1;
        }
        else
        {
            final = i;
        }
    }
    return -1;
}


int main() {
    int tamanho = pow(2,16);
    int vetor [tamanho];
    printf("Vetor tem tamanho de %d", tamanho);


    busca_Binaria(vetor, 1, tamanho);
    return 0;
}
