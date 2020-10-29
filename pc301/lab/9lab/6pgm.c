#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc, char const *argv[])
{
    int rank, size;

    int size_array = atoi(argv[1]);

    int n_elements_received;

    int * array = (int*)malloc(size_array * sizeof(int));

    int a2[1000];

    for(int i=0; i<size_array; i++) {
        array[i] = rand()%30;
    }

    for(int i=0; i<size_array; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Request request;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
      int index, i;  
      int elem_per_process = size_array / size;
      int master_min;

      if(size > 1) {
          for(i=1; i<size - 1; i++) {
              index = i * elem_per_process;

              MPI_Send(&elem_per_process, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
              MPI_Send(&array[index], elem_per_process, MPI_INT, i, 0, MPI_COMM_WORLD);
          }

          index = i * elem_per_process;

          int elements_left = size_array - index;

          MPI_Send(&elements_left, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
          MPI_Send(&array[index], elements_left, MPI_INT, i, 0, MPI_COMM_WORLD);
      }

      int min = __INT_MAX__;

      for(int i=0; i<elem_per_process; i++) {
          if(array[i] < min) {
              min = array[i];
          }
      }
     
      int tmp;
      for(int i=1; i<size; i++) {
          MPI_Recv(&tmp, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
          if(tmp < min) {
              min = tmp;
          }
      }

      printf("minimum = %d\n", min);
    }
    else {
        MPI_Recv(&n_elements_received, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(&a2, n_elements_received, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

        int min = __INT_MAX__;
        for(int i=0; i<n_elements_received; i++) {
            if(array[i] < min) {
                min = array[i];
            }
        }

        MPI_Send(&min, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}
