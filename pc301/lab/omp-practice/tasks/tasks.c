#include<omp.h>
#include<stdio.h>

int main() {
   #pragma omp parallel
   {
       #pragma omp task
       printf("task created by thread=%d\n", omp_get_thread_num());
       #pragma omp barrier
       {
           #pragma omp single
           {
               //the thread that creates the task is not the same as the thread that executes the task
               printf("last task created by thread %d\n",omp_get_thread_num()); 
               #pragma omp task
               {
                   printf("task executed by a single thread = %d\n", omp_get_thread_num());
               }
           }
       }
   } 
} 