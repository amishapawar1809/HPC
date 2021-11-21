//OpenMP program to print Hello World using C language

#include <omp.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//omp_set_num_threads(8);
	//Beginning of parallel region
	#pragma omp parallel
	{
		printf("Hello World...from thread = %d\n", omp_get_thread_num());
	}
	//Ending of parallel region
}

