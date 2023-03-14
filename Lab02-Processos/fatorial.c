#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int num, i, j, fatorial;
    int pid[num];
    printf("Escolha um numero: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        pid[i] = fork();
        if (pid[i] == 0)
        {
            /* Processo Primario */
            fatorial = 1;
            for (j = 1; j <= i + 1; j++)
                fatorial *= j;
            printf("Resultado do fatorial de %d! e %d \n", i + 1, fatorial);
            exit(0);
        }
        else
        {
            /* Processo Secundario */
            wait(NULL);
        }
    }
    return 0;
}
