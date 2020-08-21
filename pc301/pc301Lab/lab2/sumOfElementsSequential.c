#include<stdio.h>
#include<omp.h>

int main() {
    int a[]= {1,4,1,3,4,1,5,6,1,22,3,12,54,67,78};
    int i=0, sum=0;
    double start = omp_get_wtime();
    for(i;i<15; ++i) {
        sum += a[i];
    }
    printf("\nSum is: %d\n", sum);
    double end = omp_get_wtime();
    printf("\ntotal time: %f\n", (end - start));
}