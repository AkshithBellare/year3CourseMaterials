#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int count = 0;
#pragma omp threadprivate(count)

int main() {
    int x = 10, y = 20, i;
    int a[10], b[10], c[10];
    for(i=0; i<10; ++i) {
        b[i] = c[i] = i;
    }

    printf("1.count=%d")

}