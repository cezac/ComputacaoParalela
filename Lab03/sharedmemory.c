#include <sys/shm.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int status;
void child (int* sharedVariable)
{
    *sharedVariable = *sharedVariable + 2;
}
void parent(int* sharedVariable)
{
    wait(&status);
    *sharedVariable = *sharedVariable * 4;
    printf("Novo Valor da variavel = %d\n", *sharedVariable);
}


int main(void) 
{
    int id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT|0666);
    // declara o ponteiro para inteiro
    int* sharedVariable;
    // faz o atach da regiao de memoria
    sharedVariable = (int*) shmat(id, NULL, 0);
    *sharedVariable = 1;
    printf("Variavel = %d\n", *sharedVariable);
    
    int pid = fork();

    if (pid == 0)
    {
        // processo filho
        child(sharedVariable);
    } 
    else 
    {
        // processo pai chama sua respectiva função
        //parent(sharedVariable);
          wait(&status);
          *sharedVariable = *sharedVariable * 4;
          printf("Novo Valor da variavel = %d\n", *sharedVariable);
    }
    exit(0);
}
