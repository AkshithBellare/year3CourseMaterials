#include<stdio.h>
#include<omp.h>

int main() {
    int arr[] =  {1, 2,3,4, 5, 6, 7};
    int barr[] = {2,-1,3,88,12,14,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    int carr[len];
    int i;
    //using the for clause. with schedule decided by the compiler
    #pragma omp parallel 
    {
        #pragma omp for
            for(i=0; i<len; ++i) {
                carr[i] = arr[i] + barr[i];
            }
    }
    printf("a[] : ");
    for(int i=0; i<len; ++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("b[] : ");
    for(int i=0; i<len; ++i) {
        printf("%d ",barr[i]);
    }
    printf("\n");
    for(i=0; i<len; ++i) {
        printf("a[%d] (%d) + b[%d] (%d)= c[%d] (%d)\n",i, arr[i], i, barr[i],i , carr[i]);
    }
}