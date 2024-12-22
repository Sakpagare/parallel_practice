//4.Use critical section while implementing manual reduction.

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 1000000

int main() {
    int i;
    double start_time, end_time;
    long long sum = 0;

    int *array1 = (int *)malloc(SIZE * sizeof(int));
    int *array2 = (int *)malloc(SIZE * sizeof(int));
    int *result = (int *)malloc(SIZE * sizeof(int));

    if (array1 == NULL || array2 == NULL || result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize arrays
    for (i = 0; i < SIZE; i++) {
        array1[i] = i;
        array2[i] = SIZE - i;
    }

    // Serial addition
    start_time = omp_get_wtime();
    for (i = 0; i < SIZE; i++) {
        result[i] = array1[i] + array2[i];
    }
    end_time = omp_get_wtime();
    printf("Time taken for serial addition: %f seconds\n", end_time - start_time);

    // Parallel addition using manual reduction with critical section
    start_time = omp_get_wtime();
    #pragma omp parallel
    {
        long long partial_sum = 0;

        #pragma omp for
        for (i = 0; i < SIZE; i++) {
            partial_sum += array1[i] + array2[i];
        }

        // Critical section to prevent race condition
        #pragma omp critical
        {
            sum += partial_sum;
        }
    }
    end_time = omp_get_wtime();
    printf("Time taken for parallel addition with manual reduction: %f seconds\n", end_time - start_time);

    free(array1);
    free(array2);
    free(result);

    return 0;
}

