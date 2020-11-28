#include<omp.h>
#include<stdio.h>

int main() {
    int i, n, b[50], sum=0;
    double t1, t2;
    printf("Enter n:");
    scanf("%d", &n);
    t1 = omp_get_wtime();
    #pragma omp parallel num_threads(4)
    {
        int tid = omp_get_thread_num();
        #pragma omp for reduction(+:sum)
        for(i=0; i<n; i++) {
            sum = sum + i;
            printf("tid = %d sum = %d\n", tid, sum);
        }
    }
    printf("sum = %d\n", sum);
    return 0;
}