#include "mpi.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int data=10;
    MPI_Request req
    if (rank == 0)
    {
        MPI_Isend (&data, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, );
        cout<<"Process 0 sent number " << data << " to process 1 \n";
    }
    else if (rank == 1)
    {
        MPI_Irecv (&data, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout<<"Process 1 received number " << data << " from process 0 \n";
    }
    MPI_Finalize();
    return 0;
}
