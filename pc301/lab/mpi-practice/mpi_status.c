#include<stdio.h>
#include<mpi.h>
#define MAX 100

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_rank(MPI_COMM_WORLD, &size);

    MPI_Status stat;

    int numbers[MAX];
    int num_count = 0;
    if(rank == 0) {
        num_count = 54;
        MPI_Send(numbers, num_count, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if(rank == 1) {
        MPI_Recv(numbers, MAX, MPI_INT, 0, 0, MPI_COMM_WORLD, &stat);
        MPI_Get_count(&stat, MPI_INT, &num_count);
        printf("received %d elements\n", num_count);
    }
    MPI_Finalize();
    return 0;
}
