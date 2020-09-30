#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel num_threads(19800)
    {
        #pragma omp master 
        {
            printf("total threads = %d\n", omp_get_num_threads());
        }
        //int tid = omp_get_thread_num();
        //printf("Hello word from thread = %d\n",tid);
    }
}