#include <omp.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[200];
    int b[200];
    int c[200];
    int cnt=0;
    double time = omp_get_wtime();


    for(int i=0;i<200;i++)
    {
        a[i]=i;
        b[i]=a[i];
    }
    #pragma omp parallel for schedule(dynamic)
    for(int i=0;i<200;i++)
    {
        c[i] = a[i] + b[i];
    }
    for(int i=0;i<200;i++)
        printf("%d ", c[i]);

    printf("Loop executed %d times", cnt);
    printf("Number of threads: %d", omp_get_max_threads());
    printf("\nExecution time: %f", omp_get_wtime() - time);
    return 0;
}
