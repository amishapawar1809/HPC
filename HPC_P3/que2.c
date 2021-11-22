#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 3

int A[N][N];
int B[N][N];
int C[N][N];

int main()
{
    int i,j,k;
    for (i= 0; i< N; i++)
        for (j= 0; j< N; j++)
	{
            A[i][j] = 2;
            B[i][j] = 2;
	}
    double time = omp_get_wtime();
    omp_set_num_threads(4);
    #pragma omp parallel for private(i,j,k) shared(A,B,C)
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            for (k = 0; k < N; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Result Matrix:\n");
    for (i= 0; i< N; i++)
    {
        for (j= 0; j< N; j++)
            printf("%d   ",C[i][j]);
        printf("\n");
    }

    printf ("Done In %f Seconds",omp_get_wtime() - time);
    printf("\nUsing %d Threads",omp_get_max_threads());

}
