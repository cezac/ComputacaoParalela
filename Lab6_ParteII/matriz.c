#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h> 

#define N 400
void multiply(float A[N][N], float B[N][N], float C[N][N]) {
    #pragma omp parallel
    {
        int i, j, k;
        int num_threads = omp_get_num_threads();
        int thread_id = omp_get_thread_num();
        int block_size = N / num_threads;
        int block_start = thread_id * block_size;
        int block_end = block_start + block_size;
        if(thread_id == num_threads-1) {
            block_end = N;
        }
        for(i = block_start; i < block_end; i++) {
            for(j = 0; j < N; j++) {
                C[i][j] = 0.0;
                for(k = 0; k < N; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
}

int main(int argc, char** argv) 
{
    if (argc != 2)
    {
        printf("Wrong Usage.\n Usage: %s {thread_count}", argv[0]);
        exit(1);
    }
    omp_set_num_threads(atoi(argv[1]));
    float A[N][N], B[N][N], C[N][N];

    struct timeval tv;
    double start_t, end_t, tempo_gasto;

    gettimeofday(&tv, NULL);
    double start_serial = (double) tv.tv_sec + (double)tv.tv_usec / 1000000.0;
    gettimeofday(&tv, NULL);
    start_t = (double) tv.tv_sec + (double)tv.tv_usec / 1000000.0;

    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            A[i][j] = (float) i + j;
            B[i][j] = (float) i * j;
        }
    }
    gettimeofday(&tv, NULL);
    double fim_serial = (double) tv.tv_sec + (double)tv.tv_usec / 1000000.0;
    double tserial = start_serial/fim_serial;
    printf("Tempo serial: %lf\n", tserial);

    multiply(A, B, C);
    gettimeofday(&tv,NULL); 
    end_t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
    tempo_gasto = end_t - start_t;
    printf("Tempo gasto: %f usecs", tempo_gasto);
    return 0;
}
