#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tamL = 2, tamC = 2;
    int l, c, mat[tamL][tamC], trans[tamC][tamL];

    srand(time(NULL));

    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            mat[l][c] = rand() % 20; // Ao invés de ler do teclado, resolvi utilizar a biblioteca para preencher randomicamente a matriz
        }
    }

    printf("\nMatriz original:\n");
    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            printf("%3d ", mat[l][c]);
        }
        printf("\n");
    }

    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            trans[c][l] = mat[l][c];
        }
    }

    printf("\nMatriz transposta:\n");
    for(l = 0; l < tamC; l++){
        for(c = 0; c < tamL; c++){
            printf("%3d ", trans[l][c]);
        }
        printf("\n");
    }

    return 0;
}
