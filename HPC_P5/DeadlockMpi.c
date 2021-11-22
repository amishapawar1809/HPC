#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int data;
    if (rank == 0)
    {
        data = 100;
        //data, count, datatype, destination, tag, communicator, status
        MPI_Send (&data, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        printf("Process 0 sent number %d to process 1 \n", data);
    }
    else if (rank == 1)
    {
        //data, count, datatype, source, tag, communicator, status
        MPI_Recv (&data, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received number %d from process 0 \n", data);
    }
    else if(rank == 2)
    {
        data = 200;
        MPI_Send (&data, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
        printf("Process 2 sent number %d to process 3 \n", data);
    }
    else if(rank == 3)
    {
        MPI_Recv (&data, 1, MPI_INT, 2, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 3 received number %d from process 2 \n", data);
    }
    MPI_Finalize();
    return 0;
}
