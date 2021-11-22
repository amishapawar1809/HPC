%%writefile SumOfVectors.cu
#include<stdio.h>
#include<cuda.h>

__global__ void vectorsadd(int *x,int *y, int *z)    
{
    int index=blockIdx.x * blockDim.x + threadIdx.x; 
    z[index]=x[index]+y[index];
}

int main()
{
    int n=10;
    int *a, *b, *c;
    int *dev_a,*dev_b,*dev_c;
 
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    c = (int *)malloc(n * sizeof(int));
 
    //printf("\n Enter elements of first vector\n");
    for(int i=0;i<n;i++)
    {
        //scanf("%d", &a[i]);
        a[i]=rand()%20;
    }
    //printf("\n Enter elements of second vector\n");
    for(int i=0;i<n;i++)
    {
        //scanf("%d", &b[i]);
        b[i]=rand()%20;
    }

    cudaMalloc((void **)&dev_a, n*sizeof(int));
    cudaMalloc((void **)&dev_b, n*sizeof(int));
    cudaMalloc((void **)&dev_c, n*sizeof(int));

    cudaMemcpy(dev_a, a, n*sizeof(int), cudaMemcpyHostToDevice);   
    cudaMemcpy(dev_b, b, n*sizeof(int), cudaMemcpyHostToDevice);
 
    vectorsadd<<<n,1>>>(dev_a, dev_b, dev_c); 
 
    cudaMemcpy(c, dev_c, n*sizeof(int), cudaMemcpyDeviceToHost);
    
    printf("\nElements of 1st vector:\n ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\nElements of 2nd vector:\n ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t", b[i]);
    }

    printf("\nSum of two vectors:\n ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t", c[i]);
    }

    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);
 
    free(a);
    free(b);
    free(c);

    return 0;
}