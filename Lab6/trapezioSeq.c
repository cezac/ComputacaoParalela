// Está forma foi a unica que não apresentou erro ao utilizar o OMP
#ifdef _OPENMP
int processador = omp_get_thread_num();
int num_threads = omp_get_num_threads();
#endif
// Nao estou utilizando paralelismo, o código está sendo executado sequencialmente

#include <stdio.h>
#include <math.h>
#include <omp.h>

double trapezoidal_rule(double a, double b, int n, double(*f)(double)) // Função para resolver o problema do trapézio
{
    double h = (b-a)/n;
    double sum = 0.5*(f(a) + f(b));

    for (int i = 1; i < n; i++)
    {
        double x = a + i*h;
        sum += f(x);
    }

    sum = sum*h;
    return sum;
}

int main()
{
    double a = 0.0;
    double b = 3.0;
    int n = 10;
    double integral = trapezoidal_rule(a, b, n, sin);

    printf("Integral = %f\n", integral);
    return 0;
}
