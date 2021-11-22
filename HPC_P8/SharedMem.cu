%%writefile MatrixMultiplicationShared.cu
#include<stdio.h>
#include<cuda.h>
const int row1=3, col1=3, row2=3, col2=3;

__global__ void matrixMulShared(int *l,int *m, int *n)
{
    int x=blockIdx.x;
    int y=blockIdx.y;
    int k=threadIdx.x;
 
    __shared__ int p[col1];

    n[col2*y+x]=0;

    p[k]=l[col1*y+k]*m[col2*k+x];

    __syncthreads();

    for(int i=0;i<col1;i++)
        n[col2*y+x]=n[col2*y+x]+p[i];
}

int main()
{
    int a[row1][col1];
    int b[row2][col2];
    int c[row1][col2];
    int *dev_a,*dev_b,*dev_c;

    //printf("\n Enter elements of first matrix of size "+ %d + "*" + %d + "\n", row1, col1);
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            //scanf("%d",&a[i][j]);
            a[i][j]=rand()%10;
        }
    }
    //printf("\n Enter elements of second matrix of size "+ %d + "*" + %d + "\n", row2, col2);
    for(int i=0;i<row2;i++)
    {
        for(int j=0;j<col2;j++)
        {
            //scanf("%d",&b[i][j]);
            b[i][j]=rand()%10;
        }
    }

    cudaMalloc((void **)&dev_a,row1*col1*sizeof(int));
    cudaMalloc((void **)&dev_b,row2*col2*sizeof(int));
    cudaMalloc((void **)&dev_c,row1*col2*sizeof(int));

    cudaMemcpy(dev_a,a,row1*col1*sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b,b,row2*col2*sizeof(int),cudaMemcpyHostToDevice);

    dim3 grid(col2,row1);

    matrixMulShared<<<grid,col1>>>(dev_a,dev_b,dev_c);

    cudaMemcpy(c,dev_c,row1*col2*sizeof(int),cudaMemcpyDeviceToHost);

    printf("\nElements of first matrix of size %d * %d \n", row1, col1);
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
 
    printf("\nElements of second matrix of size  %d * %d \n", row2, col2);
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");  
    }

    printf("\nProduct of two matrices:\n");
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col2;j++)
        {
              printf("%d\t",c[i][j]);
        }
        printf("\n");
    }

    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);

    return 0;
}
