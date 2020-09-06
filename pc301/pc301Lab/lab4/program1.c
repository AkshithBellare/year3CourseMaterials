#include<stdio.h>
#include<omp.h>

int fibo(int n);

int main() {
    int n;
    int fib;
    double st, et;
    printf("Enter the value of n:\n");
    scanf("%d", &n);
    st = omp_get_wtime();

    #pragma omp parallel shared(n)
    {
        #pragma omp single
        {
            fib = fibo(n);
        }
    }
    et = omp_get_wtime();
    printf("Fib is %d\n", fib);
    printf("Time taken is %f s\n", et - st);
}

int fibo(int n) {
    int a, b;
    if(n < 2) {
        return n;
    }
    else {
        #pragma omp task shared(a)
        {
            printf("Task created by thread %d\n n is %d\n", omp_get_thread_num(), n);
            a = fibo(n-1);
            printf("Thread executed by thread %d\ta=%d\n", omp_get_thread_num(), a);
        }

        #pragma omp task shared(b) 
        {
            printf("Task created by thread %d\n", omp_get_thread_num());
            b = fibo(n-2);
            printf("Task executed by thread %d\tb=%d\n",omp_get_thread_num(),b);
        }

        #pragma omp taskwait
        {
            return a + b;
        } 
    }
}