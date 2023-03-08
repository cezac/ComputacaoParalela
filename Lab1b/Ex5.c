#include<stdio.h>
#include<stdlib.h>

int main () {
    int k, c, m, d, n, i, j;

    printf("Digite a dimensao da matriz: \n");
    scanf("%d %d", &k, &c);

	int a[k][c];
	//aqui foi tirada a matriz b, que era desnecessária.

    printf("Digite os valores da matriz --> \n");
    for (i=0; i<k; i++){
        printf("Digite os valores para a %d linha: \n", i+1);
        for (j=0; j<c; j++)
            scanf("%d", &a[i][j]);
}

    printf("A matriz digitada é: \n");
    for (i=0; i<k; i++){
        for (j=0; j<c; j++){
            printf("%d ", a[i][j]);
            }
            printf("\n");
        }

    printf("Digite 1 para multiplicar uma linha ou 2 para multiplicar uma coluna: \n");
    scanf("%d",&d);
    if(d > 2 || d < 1)
        printf("Entrada invalida\n");
    else {

        if (d == 1)   {

            printf("Digite qual a linha deve ser multiplicada: \n");
            scanf("%d",&m);

            printf("Digite o valor pelo qual quer multiplicada: \n");
            scanf("%d",&n);

	        for (i=0; i<c; i++) {
	            a[m-1][i] = n * a[m-1][i]; //usa-se somente a matriz a percorrendo as colunas (limite: variável c).
            }

            printf("A matriz multiplicada é: \n");
	        for (i=0; i<k; i++) {
	            for (j=0; j<c; j++) {
	                printf("%d ", a[i][j]); //imprime-se a matriz já multiplicada.
                }
                printf("\n");
	        }
	    }

        if (d == 2){

            printf("Digite qual a coluna deve ser multiplicada: \n");
            scanf("%d",&m);

            printf("Digite o valor pelo qual quer multiplicar: \n");
            scanf("%d",&n);

         	for (j=0; j<k; j++) {
	            a[j][m-1] = n * a[j][m-1]; //usa-se somente a matriz a percorrendo as linhas (limite: variável k).
            }

            printf("A matriz multiplicada é: \n");
	        for (i=0; i<k; i++) {
	            for (j=0; j<c; j++) {
                    printf("%d ", a[i][j]);
                 }
                printf("\n");
	        }

        }
    }

getchar();
return 0; //faltava return 0;
}
