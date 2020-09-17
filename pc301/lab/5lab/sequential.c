#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>
void linearSearch(int* array, int beg, int end, int key) {
    for(int i=beg; i<end; i++) {
           if(array[i] == key) {
               printf("key=%d found at index=%d\n",array[i],i);
               return ;
           }
       }
       printf("key not found\n");
}

void paralleLinear(int* array, int SIZE, int key) {
    #pragma omp parallel for 
    for(int i=0; i<SIZE; i++) {
        if(array[i] == key) {
            printf("key=%d found at index=%d\n",key,i);
        }
    }
}

void parallelLinearUsingTasks(int* array, int SIZE, int key) {
    int step_size = 0;
    #pragma omp parallel
    {
        #pragma omp single 
        {
            step_size = SIZE / omp_get_num_threads();
            for(int i=0; i<SIZE; i+=step_size) {
                #pragma omp task 
                {
                    linearSearch(array,i,i+step_size-1,key);
                }
            }
        }
    }
}

int* generateArray(int num) {
    int* ptr = (int*) malloc (num*sizeof(int));
    if(ptr!=NULL) {
        for(int i=0; i<num; i++) {
            ptr[i] = rand()%num;
        }
    }
    return ptr;
}

int binarySearch(int* array, int l, int r, int key) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (array[mid] == key) 
            printf("key=%d found at index=%d\n", key, mid);
            return mid;
        if (array[mid] > key) 
            return binarySearch(array, l, mid - 1, key); 
        return binarySearch(array, mid + 1, r, key); 
    } 
    printf("key not found");
    return -1;
} 

int main(int c, char** argv) {
   int SIZES[7] = {100,1000,10000,100000,1000000,10000000,100000000};
   for(int i=0; i<7; i++) {
      printf("SIZE=%d\n",SIZES[i]);
      int* array = generateArray(SIZES[i]);
      int key = rand()%(SIZES[i]);
      
      double start = omp_get_wtime();
      linearSearch(array,0,SIZES[i],key);
      double end = omp_get_wtime();
      printf("LINEAR SEARCH time=%f\n\n",end-start);

      start = omp_get_wtime();
      paralleLinear(array,SIZES[i],key);
      end = omp_get_wtime();
      printf("PARALLEL LINEAR SEARCH time=%f\n\n",end-start);

      start = omp_get_wtime();
      binarySearch(array,0,SIZES[i]-1,key);
      end = omp_get_wtime();
      printf("LINEAR BINARY SEARCH time=%f\n\n",end-start);
   }
}