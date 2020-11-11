#include<stdio.h>
#include<mpi.h>

void my_bcast(int rank, int size) {
   int token;
   if(rank == 0)  {
       token = -1;
       for(int i=1; i<size; i++) {
           MPI_Send(&token, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
       }
   }
   else {
       MPI_Recv(&token, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
       printf("process %d received %d from process 0\n", rank, token);
   }
}

int main(int argc, char *argv[])
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int data;

    if(rank == 0) {
        data = -12;
    }

    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("data=%d\n", data);

    MPI_Finalize();
    return 0;
}
