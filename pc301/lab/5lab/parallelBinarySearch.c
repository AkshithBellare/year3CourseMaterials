#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define SIZE 1000

void binarySearch(int* a, int beg, int end, int key) {
   if(beg <= end) {
       int mid = (beg + end)/2;
       if(a[mid] == key) {
           printf("key found! %d", mid);
       } else if(a[mid] < key) {
           return binarySearch(a,mid+1,end,key);
       } else return binarySearch(a,beg,mid-1,key);
    }
}

void parallelBinarySearch(int *a, int beg, int end, int key) {
    if(beg <= end) {
        int mid = (beg + end) / 2;
        if(a[mid] == key) {
            printf("key=%d fount at index=%d",a[mid], mid);
        } else if(a[mid] < key) {
            #pragma omp task
            {
                parallelBinarySearch(a,mid+1,end,key);
            }
        } else if(a[mid] > key) {
            #pragma omp task
            {
                parallelBinarySearch(a,beg,mid-1,key);
            }
        }
    }
}

int binary_search(int arr[],int l,int r, int key){
    if(l>=r)return -1;
    int mid=(l+r)/2;
    if(arr[mid]==key)return mid;
    int a = -1,b = -1;

    #pragma omp task shared(a) 
    {
      a = binary_search(arr,mid+1,r, key);
    }

    #pragma omp task shared(b)
    {
       b =  binary_search(arr,l,mid, key);
    }
    #pragma omp taskwait
     if(a==-1 && b==-1)
     {
       return -1;
     }
     if(a==-1)
     {
       return b;
     }
    if(b==-1)
    {
      return a;
    }
}

int main() {
    int testArray[10] = {1,2,3,4,5,6,7,8,9,10};

    binarySearch(testArray,0,9,7);

    #pragma omp parallel 
    {
        #pragma omp single
        {
            parallelBinarySearch(testArray,0,9,7);
        }
    }

    printf("%d", binary_search(testArray,0,9,7));
}