//5.WAP to demonstrate omp master

#include <stdio.h>
#include <omp.h>

int main() {
    int i;

    #pragma omp parallel
    {
       
        #pragma omp master
        {
	   	printf("This is executed by the master thread only.\n");
        }

       
        printf("Thread %d is executing this part.\n", omp_get_thread_num());
    }

    return 0;
}

