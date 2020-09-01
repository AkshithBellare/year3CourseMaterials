#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define SIZE 7
void printArray(int *arr) {
    for(int i=0; i<SIZE; ++i) {
        printf("%d ", *arr);
        arr++;
    }
}
int main() {
    srand(0);
    int my_array[] = {1,5,4434,23423,0,1231,-1};
    //for(int i=0; i<SIZE; ++i) {
    //    my_array[i] = rand();
    //}
    int min_value = my_array[0];
    int i;
    #pragma omp parallel for schedule(static)
    for(i=0; i<SIZE; ++i) {
        if(my_array[i] < min_value) {
            min_value = my_array[i];
        }
    }
    printf("minvalue is %d\n", min_value);
    printArray(my_array);
}