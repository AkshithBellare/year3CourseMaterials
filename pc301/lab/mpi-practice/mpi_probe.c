#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

int main(int argc, char  *argv[])
{
    MPI_Init(&argc, &argv); 
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int num_amount;

    if(rank == 0) {
        int numbers[MAX];
        srand(time(NULL));
        num_amount = (rand()/(float)RAND_MAX) * MAX;

        MPI_Send(numbers, num_amount, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if(rank == 1) {
        MPI_Status stat;

        MPI_Probe(0, 0, MPI_COMM_WORLD, &stat);
        
        MPI_Get_count(&stat, MPI_INT, &num_amount);

        int* num_buf = (int*) malloc (num_amount * sizeof(int));

        MPI_Recv(num_buf, num_amount, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("received %d number of elements of numbers array\n", num_amount);
    }
    MPI_Finalize();
    return 0;
}
