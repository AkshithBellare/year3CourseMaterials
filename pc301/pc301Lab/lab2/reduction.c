#include<stdio.h>
#include<omp.h>
int main() {
    int x = 0;
    #pragma omp parallel num_threads(6) reduction(+:x)
    {
        int id = omp_get_thread_num();
        int threads = omp_get_num_threads();
        x = x + 1;
        printf("Hi from %d\n value of x: %d\n", id, x);
    }
    printf("Final x : %d\n", x);
    return 0;
}