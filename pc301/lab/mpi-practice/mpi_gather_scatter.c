#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>

float* create_random_nums(int num_elements) {
    srand(0);
    float* array = (float*) malloc (num_elements * sizeof(float));

    for(int i=0; i<num_elements; i++) {
        array[i] = rand() / 1000000000;
    }

    return array;
}

float compute_avg(float* sub_nums, int size) {
    float avg = 0.0;

    for(int i=0; i<size; i++) {
        avg += sub_nums[i];
    }

    return avg/size;
}

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int elements_per_proc = 4;
    float* rand_nums = NULL;

    if(rank == 0) {
        rand_nums = create_random_nums(elements_per_proc * size);
        for(int i=0; i<elements_per_proc*size; i++) {
            printf("%f ", rand_nums[i]);
        }
    }

    float* sub_rand_nums = (float*) malloc (elements_per_proc * sizeof(int));

    MPI_Scatter(rand_nums, elements_per_proc, MPI_FLOAT, sub_rand_nums, elements_per_proc, MPI_FLOAT, 0, MPI_COMM_WORLD);

    float sub_avg = compute_avg(sub_rand_nums, elements_per_proc);

    float* sub_avgs = NULL;
    if(rank == 0) {
        sub_avgs = (float*)  malloc (size * sizeof(int));
    }

    MPI_Gather(&sub_avg, 1, MPI_FLOAT, sub_avgs, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        float avg = compute_avg(sub_avgs, size);
        printf("average = %f\n", avg);
    }

    MPI_Finalize();

    return 0;
}
