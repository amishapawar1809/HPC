%%writefile SumOfVectorsPrivate.cu
#include<stdio.h>
#include<cuda.h>

__global__ void vectorsadd(int *x,int *y, int *z)    //kernel definition
{
    int index=threadIdx.x; 
    int p=x[index]+y[index];
    z[index]=p;
}

int main()
{
    int n=10;
    int a[n], b[n],c[n];
    int *d,*e,*f;
    //printf("\n Enter elements of first array\n");
    for(int i=0;i<n;i++)
    {
        //scanf("%d",&a[i]);
        a[i]=rand()%10;
    }
    //printf("\n Enter elements of second array\n");
    for(int i=0;i<n;i++)
    {
        //scanf("%d",&b[i]);
        b[i]=rand()%10;
    }

    cudaMalloc((void **)&d,n*sizeof(int));
    cudaMalloc((void **)&e,n*sizeof(int));
    cudaMalloc((void **)&f,n*sizeof(int));

    cudaMemcpy(d,a,n*sizeof(int),cudaMemcpyHostToDevice);   
    cudaMemcpy(e,b,n*sizeof(int),cudaMemcpyHostToDevice);
 
    vectorsadd<<<n,10>>>(d,e,f); 

    cudaMemcpy(c,f,n*sizeof(int),cudaMemcpyDeviceToHost);
    
    printf("\nElements of 1st array:\n ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }

    printf("\nElements of 2nd array:\n ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",b[i]);
    }

    printf("\nSum of two arrays:\n ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",c[i]);
    }

    /* Free the memory allocated to pointers d,e,f */
    cudaFree(d);
    cudaFree(e);
    cudaFree(f);

    return 0;
}
