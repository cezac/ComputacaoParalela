// ANDRE CUNHA QUINTILIANO DE CAMARGO - 32073801
// Caio Cezar Oliveria Filardi do Carmo - 31891365

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <tgmath.h>

double Trapezio (double a, double b, int n, double * global_result_p, double(*f)(double));

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

#pragma omp parallel num_threads(thread_count)

    Trapezio(a, b, n, &global_result, sin);

    printf("Com n = %d trapezios, a estimativa\n", n);
    printf("da intregral de %f para %f = %.14e\n", a, b, global_result);
    return 0;
}

double Trapezio (double a, double b, int n, double * global_result_p, double(*f)(double)){
    double h, x, my_result;
    double local_a, local_b;
    int i, local_n;
#ifdef _OPENMP
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
#else
    int my_rank = 0;
    int thread_count = 1;
#endif

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
#pragma omp critical
    *global_result_p += my_result;
}
