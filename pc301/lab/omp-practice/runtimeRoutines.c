#include<omp.h>
#include<stdio.h>

int main() {
    int numthreads;
    omp_set_dynamic(0);
    omp_set_num_threads(omp_get_num_procs());
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        #pragma omp single 
        {
           numthreads = omp_get_num_threads(); 
           printf("Numthreads=%d", numthreads);
        }
    }
}