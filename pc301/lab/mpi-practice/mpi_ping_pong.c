#include<stdio.h>
#include<mpi.h>
#define PING_PONG_LIMIT 20

// why doesn't the printing happen in the same order as sending and receiving?

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int ping_pong_count = 0;
    int partner_rank = (rank + 1)%2;

    while(ping_pong_count < PING_PONG_LIMIT) {
        if(rank == ping_pong_count % 2) {
            ping_pong_count += 1;
            MPI_Send(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD);
            printf("%d sent to %d : pingpongcount = %d\n", rank, partner_rank, ping_pong_count);
        }
        else {
            MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("%d received from %d: pingpongcount = %d\n", rank, partner_rank, ping_pong_count);
        }
    }
    MPI_Finalize();
    return 0;
}
