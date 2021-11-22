//Vector-vector addition in worksharing using shared clause
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
	cout<<"First vector:\n";

	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Second Vector:\n";
	for(i=0;i<n;i++){
		cin>>b[i];
	}
    #pragma omp parallel shared(i, a, b, c)
	{
		#pragma omp for
 		for(i=0; i<n; i++)
 		{
 		    c[i]=b[i]+a[i];
        }

	}
    cout<<"Due to shared:"<<i<<"\n";
    cout<<"Output Vector:\n";
	printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
    for(i=0;i<n;i++)
    {
    	printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);

	}
	return 0;


}
