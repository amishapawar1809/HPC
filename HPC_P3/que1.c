#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n){

    int i,j;
	#pragma omp parallel for shared (arr, n) private (i,j)
	for(i =0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[i], arr[j+1]);
        }
	}
}

void sort_des(int arr[], int n)
{
    int i,j;
	#pragma omp parallel for shared (arr, n) private (i,j)
	for(i =0; i < n; ++i)
    {
        for (j = i+1; j < n; ++j)
        {
            if(arr[i] < arr[j])
                swap(arr[i], arr[j]);
        }
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main()
{
    int n, i, sum;
    printf("Enter size: ");
    scanf("%d", &n);

	int arr1[n], arr2[n];

    printf("Enter 1st vector elements:\n");
	for(i=0; i<n; i++)
    {
		scanf("%d", &arr1[i]);
	}
	printf("Enter 2nd vector elements:\n");
	for(i=0; i<n; i++)
    {
		scanf("%d", &arr2[i]);
	}
	sort(arr1, n);
    sort_des(arr2, n);
    sum=0;

    #pragma omp parallel private(i)
    {
        #pragma omp for reduction(+:sum)
		for (i=0; i<n; i++)
        {
			sum += (arr1[i] * arr2[i]);

		}
    }
    printf("Sum = %d\n", sum);

	free(arr1);
	free(arr2);

}
