#include<stdio.h>
#include<omp.h>
int main() {
    int x = 100; //the combined value is going to be added to whatever x had before
    #pragma omp parallel num_threads(6) reduction(+:x)
    {
        printf("value of x after entering parallel region=%d\n", x);
        int id = omp_get_thread_num();
        int threads = omp_get_num_threads();
        x = x + 1;
        printf("Hi from %d\n value of x: %d\n", id, x);
    }
    printf("Final x : %d\n", x);
    return 0;
}
