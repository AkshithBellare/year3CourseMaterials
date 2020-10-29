#include<mpi.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int size, myrank, x, i;
    MPI_Status status;
    MPI_Request request;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if(myrank == 0) {
        x = 10;
        MPI_Isend(&x, 1, MPI_INT, 1, 20, MPI_COMM_WORLD, &request);
        printf("Send returned immediately\n");
    }
    else if(myrank == 1) {
        printf("Value of x is: %d\n", x);
        //MPI_Irecv(&x, 1, MPI_INT, 0 , 20, MPI_COMM_WORLD, &request);
        //MPI_Wait(&request, &status);
        printf("Value of x is: %d\n", x);
        printf("Receive returned immediately\n");
    }
    MPI_Finalize();
    return 0;
}
