#include<omp.h>
#include<stdio.h>

int main() {
   int x = 1;
   #pragma omp parallel 
   {
       printf("%d", x);
   } 
}