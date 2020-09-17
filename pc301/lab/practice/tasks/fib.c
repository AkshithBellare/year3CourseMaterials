//NOTE: This program doesn't prove anything. The parallel program takes forever.Figure out why!
#include<stdio.h>
#include<omp.h>

int serialFib(int n) {
    int x, y;
    if(n <= 2){ // fib(1) = 1
        return n-1;
    }
    x = serialFib(n-1);
    y = serialFib(n-2);
    return x + y;
}

int parallelFib(int n) {
    int x, y;
    if(n<=2) {
        return n-1;
    }
    #pragma omp task shared(x)
    {
        x = parallelFib(n-1);
    }
    #pragma opm task shared(y)
    {
        y = parallelFib(n-2);
    }
    #pragma omp taskwait
    return x + y;
}

int main() {
    double start,end;
    int fib=0;
    start = omp_get_wtime();
    fib = serialFib(38);
    printf("Fib(5)=%d\n", fib);
    end = omp_get_wtime();
    printf("\nserial fib time=%f\n", end - start);

    start = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single
        {
            fib = parallelFib(38);
            printf("Fib(5)=%d\n", fib);
        }
    }
    end = omp_get_wtime();
    printf("\nparallel fib time=%f\n", end - start);

}