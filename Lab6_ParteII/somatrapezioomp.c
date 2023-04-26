// ANDRE CUNHA QUINTILIANO DE CAMARGO - 32073801
// Caio Cezar Oliveria Filardi do Carmo - 31891365
// O código permanece o mesmo do laboratório anterior, com alteração nas execuções com diferentes números de threads

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <tgmath.h>

double Trapezio (double a, double b, int n, double* global_result_p);

int main (int argc, char* argv[]){
    double global_result = 0.0;
    double a, b;
    int n;
    int thread_count;

    thread_count = strtol(argv[1], NULL, 10);

    printf("Entre a variavel a: \n");
    scanf("%lf", &a);
    printf("Entre a variavel b: \n");
    scanf("%lf", &b);
    printf("Entre a variavel n : \n");
    scanf("%d", &n);

#pragma omp parallel num_threads(thread_count) // Especificação do números de threads - alterar váriavel de threads para 1, 2, 4, 6 e 8

    Trapezio(a, b, n, &global_result);

    printf("Com n = %d trapezios, a estimativa\n", n);
    printf("da intregral de %f para %f = %.14e\n", a, b, global_result);
    return 0;
}

double Trapezio (double a, double b, int n, double* global_result_p)){
    
    double h, x, my_result;
    double local_a, local_b;
    int i, local_n;
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    h = (b-a)/n;
    local_n = n/thread_count;
    local_a = a + my_rank * local_n * h;
    local_b = local_a + local_n * h;
    my_result = (f(local_a) + f(local_b))/2.0;
    for (i = 1; i <= local_n-1; i++){
        x = local_a + i * h;
        my_result += x;
    }
    my_result = my_result * h;
#pragma omp critical // Acesso a região crítica
    *global_result_p += my_result;
}
