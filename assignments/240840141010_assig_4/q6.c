#include <stdio.h>
#include <omp.h>

int main() {
    int i;

    #pragma omp parallel
    {
        #pragma omp single
        {
            printf("This part is executed by a single thread.\n");
        }

        printf("Thread %d is executing this part.\n", omp_get_thread_num());
    }

    return 0;
}

