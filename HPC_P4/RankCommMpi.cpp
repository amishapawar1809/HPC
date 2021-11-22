#include "mpi.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int rank, size, length;
    char proc[100];
    MPI_Comm comm;
    char name[MPI_MAX_OBJECT_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Get_processor_name(proc, &length);
    MPI_Comm_get_name(MPI_COMM_WORLD, name, &length);
    cout << "Name of communicator: " << name << " :: ";
    cout << "Hello, MPI-- Rank: " << rank << ", " << "Size: " << size << ", " << "on " << proc <<"\n";
    MPI_Finalize();
    return 0;
}
