#include<omp.h>
#include<stdio.h>
#define NUM_THREADS 4
int main() {
    int a[] = {1,4,1,3,4,1,5,6,1,22,3,12,54,67,78};
    int len = sizeof(a)/sizeof(a[0]);
    printf("\nlength: %d\n", len);
    int sum[NUM_THREADS];
    int s = 0;
    int i,nthreads;
    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();
    #pragma omp parallel 
    {
        int i,id ,nthrds;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        printf("\nid: %d nthrds: %d\n", id, nthrds);
        if(id ==0) nthreads = nthrds;
        for(i=id, sum[id]=0; i<len; i+=nthrds) {
            sum[id] += a[i];
        }
        printf("\nsum[%d]: %d\n", id, sum[id]);
    }
    double end = omp_get_wtime();
    printf("\ntotal time taken: %f\n", (end - start));
    for(i=0; i<nthreads; ++i) {
        s += sum[i];
    }
    printf("\nSum of the array is: %d\n", s);
}