//7.Data creation inside parallel region using single

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100

int main() {
    int i;
    int *array = NULL;

    #pragma omp parallel
    {
        #pragma omp single
        {
            array = (int *)malloc(SIZE * sizeof(int));
            if (array == NULL) {
                exit(1);
            }

            for (i = 0; i < SIZE; i++) {
                array[i] = i * 2;
            }
            printf("Array initialized by thread %d.\n", omp_get_thread_num());
        }

        #pragma omp for
        for (i = 0; i < SIZE; i++) {
            array[i] += 5;
        }

        #pragma omp for
        for (i = 0; i < SIZE; i++) {
            printf("Thread %d: array[%d] = %d\n", omp_get_thread_num(), i, array[i]);
        }
    }

    free(array);
    return 0;
}

