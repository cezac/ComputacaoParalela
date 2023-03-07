#include <stdio.h>
#include <string.h>

int main(){
  
	const int BUFFER_SIZE = 300;
	char p1[BUFFER_SIZE];
	char p2[BUFFER_SIZE];

	printf("Digite o nome da primeira pessoa: ");
	fgets(p1, 300, stdin);

	printf("Digite o nome da segunda pessoa: ");
	fgets(p2, 300, stdin);

	int result = strcmp(p1, p2);

    printf("\n");

	if (result < 0){
		printf("%s", p1);
		printf("\n");
		printf("%s", p2);
	}
	else if (result > 0){
		printf("%s", p2);
		printf("\n");
		printf("%s", p1);
	}
	else printf("Os nomes sao iguais");
}
