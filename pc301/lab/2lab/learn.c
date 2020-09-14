//Learn concept of private() and firstprivate();

#include<omp.h>
#include<stdio.h>
int main() {
    int i = 10;
    printf("\nValue before pragma i = %d\n", i);
    #pragma omp parallel num_threads(4) private(i) 
    {
        printf("\nValue after entering pragma i = %d Thread id(tid) = %d\n", i, omp_get_thread_num());
        i = i + omp_get_thread_num();
        printf("\nValue after changing value , i = %d Thread id(tid) = %d\n", i, omp_get_thread_num());
    }
    printf("\nValue after pragma i = %d\n", i);
}