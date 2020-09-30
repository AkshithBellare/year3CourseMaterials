#include<stdio.h>
#include<omp.h>

int main() {
    int i;
    #pragma omp parallel for 
    for(i=0; i<10; ++i) {
        printf("%d tid=%d", i, omp_get_thread_num());
    }
}