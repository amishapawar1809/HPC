#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[])
{
    int rank, np, root = 0;
    int value, sum = 0;
    int	src, src_tag;
    int dest, dest_tag;
    MPI_Status  status;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&np);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if (rank == root)
    {
        dest = rank + 1;
        dest_tag = 0;
        MPI_Send(&rank, 1, MPI_INT, dest, dest_tag, MPI_COMM_WORLD);
    }
    else
    {
        if(rank<np-1)
        {
            src = rank - 1;
            src_tag = 0;
            MPI_Recv(&value, 1, MPI_INT, src, src_tag, MPI_COMM_WORLD, &status);
            sum  = rank + value;
            dest = rank + 1;
            dest_tag = 0;
            MPI_Send(&sum, 1, MPI_INT, dest, dest_tag, MPI_COMM_WORLD);
        }
        else
        {
            src = rank - 1;
            src_tag = 0;
            MPI_Recv(&value, 1, MPI_INT, src, src_tag, MPI_COMM_WORLD, &status);
            sum = rank + value;
        }
        printf("Process %d --> Sum = %d\n", rank, sum);
    }
    if (rank == root)
    {
        src = np - 1;
        src_tag = 0;
        MPI_Recv(&sum, 1, MPI_INT, src, src_tag, MPI_COMM_WORLD, &status);
        printf("Process %d --> Final sum %d\n", rank, sum);

    }
    if(rank == (np - 1))
    {
       dest = 0;
       dest_tag = 0;
       MPI_Send(&sum, 1, MPI_INT, dest, dest_tag, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}

