#include <iostream>
#include <omp.h>
using namespace std;

#define N 3

int a[N][N], b[N][N], c[N][N];

int main()
{
    int i,j,k;
    //cout<<"Enter 1st matrix: ";
    for (i= 0; i< N; i++)
        for (j= 0; j< N; j++)
	{
            cin>>a[i][j];
	}
    //cout<<"\nEnter 2nd matrix: ";
	for (i= 0; i< N; i++)
        for (j= 0; j< N; j++)
	{
            cin>>b[i][j];
	}

    omp_set_num_threads(4);
    #pragma omp parallel for private(i,j,k) shared(a,b,c)
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            for (k = 0; k < N; ++k)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout<<"\n1st Matrix:\n";
    for (i= 0; i< N; i++)
    {
        for (j= 0; j< N; j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }

    cout<<"\n2nd Matrix:\n";
    for (i= 0; i< N; i++)
    {
        for (j= 0; j< N; j++)
            cout<<b[i][j]<<" ";
        cout<<"\n";
    }

    cout<<"\nResult Matrix:\n";
    for (i= 0; i< N; i++)
    {
        for (j= 0; j< N; j++)
            cout<<c[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
