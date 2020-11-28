#include <omp.h>
#include<stdio.h>

int main() {
    int a[5], i;
    #pragma omp parallel
    {
        #pragma omp for
        for(i = 0; i<5; i++) {
            a[i] = i * i;
        }

        #pragma omp master 
        {
            for(i = 0; i<5; i++) {
                printf("a[%d] = %d\n", i, a[i]);
            }
        }
        //no barrier at the end her
        printf("tid=%d\n", omp_get_thread_num());

        #pragma omp for 
        for(i=0; i<5; i++) {
            a[i] += i;
        }

        #pragma omp single
        {
            printf("tid thread inside single = %d\n", omp_get_thread_num());
            for(i =0; i<5; i++) {
                printf("a[%d] = %d\n", i, a[i]);
            }
        }
    }
    return 0;
}