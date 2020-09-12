#include<stdio.h>
#include<omp.h>

int main() {
    int arr[] =  {1, 2,3,4, 5, 6, 7};
    int barr[] = {2,-1,3,88,12,14,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    int carr[len];
    int i;
    #pragma omp parallel
    {
        #pragma omp for
            for(i=0; i<len; ++i) {
                carr[i] = arr[i] + barr[i];
            }
    }

    for(i=0; i<len; ++i) {
        printf("%d ",carr[i]);
    }
}