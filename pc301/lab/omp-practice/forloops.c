#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main() {
  int N = 100; 
  #pragma omp parallel shared(N)
  {
     int n_threads = omp_get_num_threads();
     int tid = omp_get_thread_num();
     
     int beg = (tid * N)/n_threads;
     int end = ((tid + 1) * N)/n_threads;

     for(int i=beg; i<end; ++i) {
         printf("%d\t%d\n", omp_get_thread_num(), i);
     }
  }
    printf("\nparallel region 2\n");
  #pragma omp parallel for shared(N) schedule(static, 25)
      for(int i=0; i<N; ++i) {
        printf("%d\t%d\n", omp_get_thread_num(), i);
      }
  printf("\n");
}