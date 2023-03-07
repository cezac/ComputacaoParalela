#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int num = 0;
	printf("Digite o numero para gerar: ");

	scanf("%d", &num);
	if (num & 1 ==0){
		printf("Numero informado deve ser impar!");
		exit(1);
	}
	int median = (num/2) + 1;
	int i = 1;
	for(i; i <= median; i++){
		int k = 1;
		for(k; k < i; k++){
			printf(" ");
		}
		int j = i;
		for (j; j < median; j++)
		{
			printf("%d ", j);		
		}
		printf("%d ", median);
		for (j = median + 1; j<= num+1-i;j++)
		{
			printf("%d ", j);
		}
		printf("\n");
	} 
}
