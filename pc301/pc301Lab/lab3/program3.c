#include<stdlib.h>
#include<stdio.h>
#include<omp.h>

int main() {
    int i,j;
    #pragma omp parallel
    {
        #pragma omp for schedule(static, 3) private(i,j)
        for(i =0; i<6; ++i) {
            for(j=0; j<5; ++j) {
                int tid2 = omp_get_thread_num();
                printf("tid = %d, i = %d, j = %d\n", omp_get_thread_num(), i, j);
            }
        }
    }
    return 0;
}