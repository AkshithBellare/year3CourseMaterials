#include<omp.h>
#include<stdio.h>
#define NUM_THREADS 4
int main() {
    int a[] = {1,4,1,3,4,1,5,6,1,22,3,12,54,67,78};
    int len = sizeof(a)/sizeof(a[0]);
    printf("\nlength: %d\n", len);
    int sum[NUM_THREADS]; //array to store the sum calculated by each thread.
    int s = 0; //holds the sum of sums calculated by each thread
    int i,nthreads;
    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();
    #pragma omp parallel 
    {
        int i,id ,nthrds;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        printf("\nid: %d nthrds: %d\n", id, nthrds);
        //if master thread set the number of threads. Threads allocated might be lesser than what we set.
        if(id ==0) nthreads = nthrds;         
        //calculating sum in a round robin approach
        for(i=id, sum[id]=0; i<len; i+=nthrds) {
            sum[id] += a[i];
        }
        printf("\nsum[%d]: %d\n", id, sum[id]);
    }
    double end = omp_get_wtime();
    printf("\ntotal time taken: %f\n", (end - start));
    for(i=0; i<nthreads; ++i) {
        s += sum[i]; //summing up sums calculated by each thread
    }
    printf("\nSum of the array is: %d\n", s);
}