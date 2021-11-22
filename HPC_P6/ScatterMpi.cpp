#include "mpi.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int arr[size], data, i;
    if (rank == 0)
    {
        for (i=0; i<size; i++)
            arr[i] = i;
        printf("1. Processor %d has data: ", rank);
        for (i=0; i<size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    MPI_Scatter(arr, 1, MPI_INT, &data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("2. Processor %d has data %d\n", rank, data);
    data= 10;
    printf("3. Processor %d now has %d\n", rank, data);

    MPI_Gather(&data, 1, MPI_INT, arr, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("4. Processor %d has data: ", rank);
        for (i=0; i<size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    MPI_Finalize();
    return 0;
}
