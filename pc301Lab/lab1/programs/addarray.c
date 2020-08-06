#include <omp.h>
#include <stdio.h>
#include<time.h>
int main()
{
   int i, n, chunk;
   int a[20], b[20], c[20];
   n = 20;
   chunk = 4;
   /*initializing array*/
   for (i = 0; i < n; i++)
   {
      a[i] = i * 2;
      b[i] = i * 3;
   }
   printf("Chunk=%d", chunk);
   clock_t begin = clock();
   {
      #pragma omp parallel for default(shared) private(i) schedule(static, chunk)
         for (i = 0; i < n; i++)
         {
            c[i] = a[i] + b[i];
            printf("Thread id = %d i = %d, c[%d] = %d\n", omp_get_thread_num(), i, i, c[i]);
         }
   }
   clock_t end = clock();
   double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   printf("time spent, %f", time_spent);
}