#include<stdio.h>
#include<omp.h>
static long num_steps = 1000000000;
double step;

int main() {
    int i;
    double x, sum=0.0, pi;
    double start = omp_get_wtime();
    #pragma omp parallel
    {
        printf("step = %f\n", step);
        int id = omp_get_thread_num();
        int div = num_steps/omp_get_num_threads();
        int start = id*div;
        printf("ID%d div%d start%d (start + div)%d sum%f\n", id,div, start, start+div, sum);
        for(i=start; i<(start + div); ++i) {
            x = (i + 0.5)*step;
            sum = sum + 4.0/(1 + x*x);
        }
    }
    double end = omp_get_wtime();
    printf("total time%f\n", end - start);
    printf("area: %f", sum * step);
    return 0;
}