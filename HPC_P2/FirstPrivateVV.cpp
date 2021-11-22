//Vector-vector addition in worksharing using firstprivate clause
#include<iostream>
#include <bits/stdc++.h>
#include<omp.h>
using namespace std;
int main(){
	int i;
	int index=0;
	int n;
	cout<<"Vector Space: ";
	cin>>n;
	int a[n+1];
	int b[n+1];
	int c[n+1];

	printf("First vector:\n");
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	printf("Second vector:\n");
	for(i=0;i<n;i++){
		cin>>b[i];
	}
    #pragma omp parallel firstprivate(index, a, b)
	{
        int thread=omp_get_thread_num();
        while(index<n)
        {
        	if(index==thread-1)
        	{
        		c[index]=a[index]+b[index];
        		printf("Thread %d works on element %d\n", thread-1, index);
        		break;
        	}
        	index++;
        }
	}
    cout<<"Due to firstprivate:"<<index<<"\n";
	cout<<"Output Vector:\n";
	printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
    for(i=0;i<n;i++)
    {
    	printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
	}
    return 0;
}
