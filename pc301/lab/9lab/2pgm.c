#include<mpi.h>
#include<stdio.h>

int main(int argc,char *argv[ ]){
    MPI_Status status;
    MPI_Request request;
    int size,myrank,x;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    if(myrank==0){
        scanf("%d",&x);
      }
    MPI_Bcast(&x,1,MPI_INT,1,MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    printf("(Value of x) in process %d : %d\n",myrank,x);
    MPI_Finalize();
    return 0;
}
