%%writefile FunctionGlobal.cu
#include<stdio.h>
#include<cuda.h>

__managed__ int a[5]; 

__global__ void funGlobal()    //kernel definition
{
    for(int i=0;i<5;i++)
    {
        printf("%d\t", a[i]);
        a[i]=a[i]*5;
    }
}

int main()
{
    for(int i=0;i<5;i++)
        a[i]=0+i;

    funGlobal<<<1,1>>>( ); 

    cudaDeviceSynchronize();

    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf("%d\t",a[i]);
    }

    return 0;
}
