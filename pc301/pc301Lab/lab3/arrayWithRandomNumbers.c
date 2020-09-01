#include<stdio.h>
#include<stdlib.h>
int main() {
    int my_array[20];
    srand(0);
    for(int i=0; i<20; ++i) {
        my_array[i] = rand();
    }
    for(int i=0; i<20; ++i) {
        printf("%d\t", my_array[i]);
    }
}