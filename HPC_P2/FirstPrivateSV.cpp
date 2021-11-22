//Scalar-vector addition in worksharing using firstprivate clause
#include<iostream>
#include <bits/stdc++.h>
#include<omp.h>
using namespace std;

int main(){
	int n,scalar;
	int i;
	cout<<"Vector Space: ";
	cin>>n;
	int a[n+1];
	int index=0;
	int c[n+1];
	cout<<"Vector:"<<"\n";
	for(i=0;i<n;i++)
    {
		cin>>a[i];
	}
	cout<<"Scalar to add: ";
	cin>>scalar;
    #pragma omp parallel firstprivate(index)
	{
        int thread=omp_get_thread_num();
        while(index<n)
        {
        	if(index==thread-1)
        	{
        		c[index]=a[index]+scalar;
        		break;
        	}
        	index++;
        }

	}

 	cout<<"Output Vector:\n";
 	printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
    for(i=0;i<n;i++)
    {
    	printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], scalar, c[i]);

	}
  return 0;
}
