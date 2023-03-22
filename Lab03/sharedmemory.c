#include <sys/shm.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int status;
void filho (int* variavel)
{
    *variavel = *variavel + 2;
}
void pai(int* variavel)
{
    wait(&status);
    *variavel = *variavel * 4;
    printf("Novo Valor da variavel = %d\n", *variavel);
}


int main(void) 
{
    int id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT|0666);
    // declara o ponteiro para inteiro
    int* variavel;
    // faz o atach da regiao de memoria
    variavel = (int*) shmat(id, NULL, 0);
    *variavel = 1;
    printf("Variavel = %d\n", *variavel);
    
    int pid = fork();

    if (pid == 0)
    {
        // processo filho
        filho(variavel);
    } 
    else 
    {
        // processo pai chama sua respectiva função
        //parent(sharedVariable);
          wait(&status);
          *variavel = *variavel * 4;
          printf("Novo Valor da variavel = %d\n", *variavel);
    }
    exit(0);
}
