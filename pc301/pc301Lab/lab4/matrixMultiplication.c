//without using threads sequential;
#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

#define SIZE 1000
int main() {
   int **mat1 = (int **) malloc (SIZE * sizeof(int*));
   int **mat2 = (int **) malloc (SIZE * sizeof(int*));
   int **res  = (int **) malloc (SIZE * sizeof(int*));
   for(int i=0; i<SIZE; ++i) {
       mat1[i] = (int*) malloc (SIZE * sizeof(int));
       mat2[i] = (int*) malloc (SIZE * sizeof(int));
       res[i]  = (int*) malloc (SIZE * sizeof(int));
   }

   for(int i=0; i<SIZE; ++i) {
       for(int j=0; j<SIZE; ++j) {
           mat1[i][j] = rand()%100;
           mat2[i][j] = rand()%100;
       }
   }

   //perform matrix multiplication 
   double st = omp_get_wtime();
   for(int i=0; i<SIZE; ++i) {
       for(int j=0; j<SIZE; ++j) {
           for(int k=0; k<SIZE; ++k) {
               res[i][j] = mat1[i][k] * mat2[k][j];
           }
       }
   }
   double et = omp_get_wtime();
   printf("total time=%f\n", et - st);
}