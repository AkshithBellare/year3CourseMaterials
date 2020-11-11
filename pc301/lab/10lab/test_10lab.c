#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>

float a2[100000000] = {0};

float* create_random_nums(int num_elements) {
    srand(0);
    float* array = (float*) malloc (num_elements * sizeof(float));

    for(int i=0; i<num_elements; i++) {
        array[i] = (rand()%20) + 60;
    }

    return array;
}

int main(int argc, char *argv[])
{
    int rank, size;
    int total_elements;
    int elem_per_proc;
    int n_elem_received;

    MPI_Status stat;
    MPI_Init(&argc, &argv);
    //setting the rank of the process into the rank variable
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    //setting the size of the process into the rank variable
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank == 0) {
        total_elements = atoi(argv[1]);
        float* array = create_random_nums(total_elements);
        int index, i;

        elem_per_proc = total_elements / size;

        //dividing the array such that each process starting from zero to the last but one process gets elem_per_proc elements
        if(size > 1) {
            for(i=1; i<size-1; i++) {
                index = i * elem_per_proc;
                MPI_Send(&elem_per_proc, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
                MPI_Send(&array[index], elem_per_proc, MPI_FLOAT, i, 0, MPI_COMM_WORLD);
            }

        index = i * elem_per_proc;
        int elem_left = total_elements - index;


        MPI_Send(&elem_left, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        
        MPI_Send(&array[index], elem_left, MPI_FLOAT, i, 0, MPI_COMM_WORLD);
    }

    float avg = 0.0;

    double t1 = MPI_Wtime();
    //master process which is process 0 calculates average for its share of elements
    for(i=0; i<elem_per_proc; i++) {
        avg += array[i];
    }

    avg = avg / elem_per_proc;

    float tmp_avg = 0.0;
    
    //receiving averages calculated by all the other processes
    for(int i=1; i<size; i++) {
        MPI_Recv(&tmp_avg, 1, MPI_FLOAT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &stat);

        int sender = stat.MPI_SOURCE;

        avg += tmp_avg;
    }

    avg = avg / size;
    double t2 = MPI_Wtime();

    printf("MPI\naverage = %f\n", avg);
    printf("time taken = %f seconds\n", t2 - t1);

    avg = 0.0;

    //calculating serial average in process 0
    t1 = MPI_Wtime();    
    for(int i=0; i<total_elements; i++) {
        avg += array[i];
    }
    avg = avg / total_elements;
    t2 = MPI_Wtime();    

    printf("SERIAL\naverage = %f\n", avg);
    printf("time taken = %f seconds\n", t2 - t1);



} else {
    //each process receives the number of elements that it will receive as well as the elements of the array
    MPI_Recv(&n_elem_received, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &stat);
    MPI_Recv(&a2, n_elem_received, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &stat);
    float partial_avg = 0.0;

    for(int i=0; i<n_elem_received; i++) {
        partial_avg += a2[i];
    }

    partial_avg = partial_avg / n_elem_received;
    //sending the partial avg  calculated to master process
    MPI_Send(&partial_avg, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
}

    MPI_Finalize();

    return 0;
}
