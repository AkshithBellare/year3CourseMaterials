#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>

int* create_random_nums(int num_elements) {
    srand(0);
    int* array = (int*) malloc (num_elements * sizeof(int));

    for(int i=0; i<num_elements; i++) {
        array[i] = (rand()%20)+10;
    }

    return array;
}

float compute_avg(int* sub_nums, int size) {
    float avg = 0.0;

    for(int i=0; i<size; i++) {
        avg += sub_nums[i];
    }

    return avg/size;
}

float compute_float_avg(float* sub_nums, int size) {
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
    double t1, t2;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int total_elements = atoi(argv[1]);
    int elements_per_proc = total_elements / size;
    int* rand_nums = NULL;

    if(rank == 0) {
        rand_nums = create_random_nums(total_elements);
        //for(int i=0; i<total_elements; i++) {
        //    printf("%f ", rand_nums[i]);
        //}
        t1 = MPI_Wtime();
    }

    int* sub_rand_nums = (int*) malloc (elements_per_proc * sizeof(int));

    MPI_Scatter(rand_nums, elements_per_proc, MPI_FLOAT, sub_rand_nums, elements_per_proc, MPI_FLOAT, 0, MPI_COMM_WORLD);

    float sub_avg = compute_avg(sub_rand_nums, elements_per_proc);

    float* sub_avgs = NULL;
    if(rank == 0) {
        sub_avgs = (float*)  malloc (size * sizeof(float));
    }

    MPI_Gather(&sub_avg, 1, MPI_FLOAT, sub_avgs, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
    if(rank == 0) {
        float avg = compute_float_avg(sub_avgs, size);
        t2 = MPI_Wtime();
        printf("average = %f\n", avg);
        printf("time taken = %f seconds\n", (t2 - t1));

        avg = 0.0;
        t1 = MPI_Wtime();
        for(int i=0; i<total_elements; i++) {
           avg += rand_nums[i];
        }
        t2 = MPI_Wtime();
        printf("average = %f\n", avg/total_elements);
        printf("time taken = %f seconds\n", (t2 - t1));

    }

    MPI_Finalize();

    return 0;
}
