#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>
#include<limits.h>
#include<omp.h>
#include<string.h>
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

int sequentialMin(int *arr, int size) {
    int min_value = INT_MAX;
    gettimeofday(&TimeValue_Start, &TimeZone_Start);
    for(int i=0; i<size; ++i)  {
        if(*arr < min_value) {
            min_value = *arr;
        }
        arr++;
    }
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    return min_value;
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
    #pragma omp parallel for schedule(runtime) reduction(min: min_value)
    for(i=0; i<size; ++i)   {
        if(arr[i] <= min_value ) {
            min_value = arr[i];
        }
    }
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    return min_value;
}


int main() {
    int SIZE[] = {5000, 10000, 50000, 100000, 1000000};
    int arr[SIZE[4]];
    int min;
    for(int i=0; i<5; ++i) {
        initArray(arr,SIZE[i]);
        min = sequentialMin(arr, SIZE[i]);
        printf("size = %-10d sequential min = %-10d time taken = %-10f ", SIZE[i], min, timeoverheadCalc());
        min = parallelMin(arr, SIZE[i]);
        printf("size = %-10d parallel   min = %-10d time taken = %-10f ", SIZE[i], min, timeoverheadCalc());
        printf("\n");
    }
}