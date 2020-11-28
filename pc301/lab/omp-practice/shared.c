#include<omp.h>
#include<stdio.h>

int main() {
    int x = 1000000;
    #pragma omp parallel firstprivate(x)
        {
            x = x + 1;
            printf("%d\t\t%d\n", omp_get_thread_num(), x);
        }
   // #pragma omp parallel firstprivate(x)
   //     {
   //         x = x + 1;
   //         printf("%d\t\t%d\n", omp_get_thread_num(), x);
   //     }
   // #pragma omp parallel firstprivate(x)
   //     {
   //         x = x + 1;
   //         printf("%d\t\t%d\n", omp_get_thread_num(), x);
   //     }
}
    