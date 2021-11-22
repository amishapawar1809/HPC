//Vector-vector addition in SPMD
#include<iostream>
#include <bits/stdc++.h>
#include<omp.h>
using namespace std;

int main(){
	int n;
	int i;
	cout<<"Vector Space: ";
	cin>>n;
	int a[n+1];
	int b[n+1];
	int c[n+1];
	cout<<" First vector:\n";
	for(i=0;i<n;i++)
    {
		cin>>a[i];
	}

	cout<<"Second vector:\n";
	for(i=0;i<n;i++)
    {
		cin>>b[i];
	}

    #pragma omp parallel num_threads(n+1)
	{
        int id, i, Nthrds, istart, iend;
        id = omp_get_thread_num();
        Nthrds = omp_get_num_threads();
        istart = id*n/Nthrds;
        iend = (id+1)*n/Nthrds;
        if(id == Nthrds-1) iend = n;
        {
            for(i = istart; i<iend; i++)
            {
                c[i] = b[i]+a[i];
                printf("Thread %d works on element %d\n", id-1, i);
            }
        }
    }

 	cout<<"Output Vector:\n";
	printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
    for(i=0;i<n;i++)
    {
    	printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
	}
  return 0;
}
