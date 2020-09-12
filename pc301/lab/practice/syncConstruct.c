#include<stdio.h>
#include<omp.h>
#define NUM_THREADS 8
static long num_steps = 10000000;
double step;

int main() {
    step = 1/(double)num_steps;
    int i, nthreads;
    double pi, sum;
    omp_set_num_threads(NUM_THREADS);
    double st = omp_get_wtime();
    #pragma omp parallel shared(sum) 
    {
        int i, id, nthrds;
        double x;
        double tmp = 0.0;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if(id==0) nthreads = nthrds;
        for(i=id; i<num_steps; i+=nthrds ) {
            x = (i + 0.5)*step;
            tmp += 4.0/(1.0 + x*x);
        }
        #pragma omp critical
        {
            sum += tmp;
        }
    }

    double et = omp_get_wtime();
    printf("total time taken = %f\n nthreads = %d\n", (et-st), nthreads);
    pi = sum * step;
    printf("%f\n", pi);
}