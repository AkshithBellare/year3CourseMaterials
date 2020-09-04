#include<stdio.h>
#include<omp.h>
#define NUM_THREADS 4
static long num_steps = 1000000;
double step;

int main() {
    step = 1/(double)num_steps;
    int i, nthreads;
    double pi, sum[NUM_THREADS];
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel 
    {
        int i, id, nthrds;
        double x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if(id==1) nthreads = nthrds;
        for(i=id, sum[id]=0.0; i<num_steps; i+=nthrds ) {
            x = (i + 0.5)*step;
            sum[id] += 4.0/(1.0 + x*x);
        }
    }
    for(i = 0; i<nthreads; ++i) pi += sum[i]*step;
    printf("%f\n", pi);
}