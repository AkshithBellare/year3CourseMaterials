#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define SIZE 10000

int main() {
    int* rowsum = (int*) malloc (SIZE * sizeof(int));
    int* colsum = (int*) malloc (SIZE * sizeof(int));

    int** matrix = (int**) malloc (SIZE * sizeof(int*));

    for(int i=0; i<SIZE; ++i) {
        matrix[i] = (int*) malloc (SIZE * sizeof(int));
    }

    for(int i=0; i<SIZE; ++i) {
        for(int j=0; j<SIZE; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("SEQUENTIAL CALCUALTION\n");
    double st = omp_get_wtime();
    for(int i=0; i<SIZE; ++i) {
        rowsum[i] = 0;
        colsum[i] = 0;
        for(int j=0; j<SIZE; ++j) {
            rowsum[i] += matrix[i][j];
            colsum[i] += matrix[j][i];
        }
    }
    double et = omp_get_wtime();
    printf("total time=%f\n", et - st);

    printf("PARALLEL CALCULATION\n");
    st = omp_get_wtime();
    #pragma omp parallel for shared(rowsum, colsum)
        for(int i=0; i<SIZE; i++) {
            rowsum[i] = 0;
            colsum[i] = 0;
            int tmp1=0, tmp2=0;
            for(int j=0; j<SIZE; ++j) {
                tmp1 += matrix[i][j];
                tmp2 += matrix[j][i];
            }
            #pragma omp critical
            {
                rowsum[i] = tmp1;
                colsum[i] = tmp2;
            }
        }
    et = omp_get_wtime();
    printf("total time=%f\n", et - st);



} 
