#include <omp.h>
#include <iostream>
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

int main()
{
    int a[1000];
    int b[1000];
    int c[1000];
    int cnt=0;
    double time = omp_get_wtime();


    for(int i=0;i<1000;i++)
    {
        a[i]=i;
        b[i]=a[i];
    }
    #pragma omp parallel for schedule(static, 500)
    for(int i=0;i<1000;i++)
    {
        c[i] = a[i] + b[i];
    }
    for(int i=0;i<1000;i++)
        printf("%d ", c[i]);
    printf("Loop executed %d times", cnt);
    printf("Execution time: %d", omp_get_wtime() - time);
    return 0;
}
