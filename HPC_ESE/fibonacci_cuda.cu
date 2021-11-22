%%writefile fibonacci.cu
#include<stdio.h>
#include<cuda.h>


// Fibonacci numbers upto n = 5
 //int f[6] = { 0, 1, 1, 2, 3, 5 };

__global__ void fiboSeries(int *a, int n)
{
    double PHI = 1.6180339;
    int f[6] = { 0, 1, 1, 2, 3, 5 };
    int index=blockIdx.x;
    if (index < 6){
        a[index]=f[index];
   }
    else{
     int t = 5, fn = 5;

     while (t < index) {
         fn = round(fn * PHI);
         t++;
     }
     a[index]=fn;
  }


}

int main()
{
    int n=10;
    int *a;
    int *dev_a;

    a = (int *)malloc(n * sizeof(int));

    cudaMalloc((void **)&dev_a, n*sizeof(int));

    cudaMemcpy(dev_a, a, n*sizeof(int), cudaMemcpyHostToDevice);

    fiboSeries<<<n,1>>>(dev_a, n);

    cudaMemcpy(a, dev_a, n*sizeof(int), cudaMemcpyDeviceToHost);

    printf("\nFibonnaci Series: ");
    for(int i=0;i<n;i++)
       printf("%d ",a[i]);

    cudaFree(dev_a);

}
