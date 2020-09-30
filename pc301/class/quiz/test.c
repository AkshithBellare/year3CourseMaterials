#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define NUMBER_SENSORS 1000
int main() {
    double temperature[NUMBER_SENSORS][24];

    srand(0);

    for(int i=0; i<1000; ++i) {
        for(int j=0; j<24; ++j) {
            temperature[i][j]= rand() % 50;
        }
    }
    double overall_average = 0.0;
    double average[NUMBER_SENSORS] = {0.0};

    #pragma omp parallel for reduction(+:overall_average)
        for(int i=1; i<NUMBER_SENSORS; ++i) 
        {
            for(int j=0; j<24; ++j) {
                int sum = temperature[i][j];
                average[i] += sum;
            }
            average[i] = average[i] / 24;
            overall_average += average[i];
        }

    for(int i=0; i<100; ++i) {
        printf("%f\n", average[i]);
    }
    overall_average = overall_average / NUMBER_SENSORS;

    printf("%f", overall_average);
}