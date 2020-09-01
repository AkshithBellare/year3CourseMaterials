#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>
#include<limits.h>
#include<omp.h>
#include<string.h>
#define SIZE1 5000
#define SIZE2 10000
#define SIZE3 50000
#define SIZE4 100000
#define SIZE5 1000000
omp_sched_t kind;
int chunk_size;

struct timeval TimeValue_Start;
struct timezone TimeZone_Start;
struct timeval TimeValue_Final;
struct timezone TimeZone_Final;
long time_start, time_end;
double time_overhead;

void initArray(int *arr, int size) {
    srand(size);
    for(int i=0; i<size; ++i) {
        *arr = rand();
        arr++;
    }
}

void printArray(int *arr, int size) {
    for(int i=0; i<size; ++i) {
        printf("%d ", *arr);
        arr++;
    }
}

double timeoverheadCalc() {
    time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    time_end   = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead = (time_end - time_start) / 1000000.0;
    return time_overhead;
}

void sequentialMin(int *arr, int size) {
    printf("Sequential execution with size = %d\n", size);
    int min = INT_MAX;
    gettimeofday(&TimeValue_Start, &TimeZone_Start);
    for(int i=0; i<size; ++i)  {
        if(*arr < min) {
            min = *arr;
        }
        arr++;
    }
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    printf("min is %d\n", min);
    printf("Time taken = %f\n", timeoverheadCalc());
}

const char* getSchedule(omp_sched_t kind) {
    char* res = "";
    switch(kind) {
        case omp_sched_static:
            res = "Static";
            break;
        case omp_sched_dynamic:
            res = "Dynamic";
            break;
        case omp_sched_guided:
            res = "Guided";
            break;
        case omp_sched_auto:
            res = "Auto";
            break;
        default:
            res = "Other";
            break;
   }
   return res;
}
int parallelMin(int *arr, int size) {
   int min_value = *arr; 
   int i;
   gettimeofday(&TimeValue_Start, &TimeZone_Start);
   #pragma omp parallel for schedule(static, 10) reduction(min: min_value)
    for(i=0; i<size; ++i)   {
        if(arr[i] <= min_value ) {
            min_value = arr[i];
        }
    }
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    printf("min is %d\n", min_value);
    printf("Time taken = %f\n", timeoverheadCalc());
}


int main() {
    int arr1[SIZE1];
    initArray(arr1, SIZE1);
    int arr2[SIZE2];
    initArray(arr2, SIZE2);
    int arr3[SIZE3];
    initArray(arr3, SIZE3);
    int arr4[SIZE4];
    initArray(arr4, SIZE4);
    int arr5[SIZE5];
    initArray(arr5, SIZE5);
    //SET SCHEDULE IN THE PARALLEL MIN FUNCTION 
    //sequentialMin(arr1, SIZE1);
    //sequentialMin(arr2, SIZE2);
    //sequentialMin(arr3, SIZE3);
    //sequentialMin(arr4, SIZE4);
    //sequentialMin(arr5, SIZE5);

    parallelMin(arr1, SIZE1);
    parallelMin(arr2, SIZE2);
    parallelMin(arr3, SIZE3);
    parallelMin(arr4, SIZE4);
    parallelMin(arr5, SIZE5);
}