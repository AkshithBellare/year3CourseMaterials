#include <stdio.h>
#include <omp.h>
#include <limits.h>
int main() {
    int arr[] = {1,2,4,5,11,2,89,12,66,123,2,1234,34,65657,12,3545,12,334,12,-12,23};
    int len = sizeof(arr)/sizeof(arr[0]);
    int max_value = INT_MIN; //set to INT_MIN as the maximum value has to be found
    int i;
    //schedule and chunk size taken from OMP_SCHEDULE env variable
    //reduction used with max operator
    #pragma omp parallel for reduction(max: max_value) schedule(runtime) 
        for(i=0; i<len; ++i) {
            if(arr[i] > max_value) {
                max_value = arr[i];
            }
        }
    //reduction clause compares the local copies of each thread and assigne the maximum value out of those
    //copies to the global max_value
    printf("Maximum value is: %d\n", max_value);
}