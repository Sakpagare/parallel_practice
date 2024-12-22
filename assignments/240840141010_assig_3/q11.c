//11.Perform error checking if we don't use openmp related flags.


#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif

#define SIZE 1000000

int main() {
    int i;
    double start_time, end_time;

    #ifndef _OPENMP
    printf("OpenMP support is not enabled. Please compile with -fopenmp flag.\n");
    return 1;
    #endif

    int *array1 = (int *)malloc(SIZE * sizeof(int));
    int *array2 = (int *)malloc(SIZE * sizeof(int));
    int *result = (int *)malloc(SIZE * sizeof(int));

    if (array1 == NULL || array2 == NULL || result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < SIZE; i++) {
        array1[i] = i;
        array2[i] = SIZE - i;
    }

    start_time = omp_get_wtime();
    for (i = 0; i < SIZE; i++) {
        result[i] = array1[i] + array2[i];
    }
    end_time = omp_get_wtime();
    printf("Time taken for serial addition: %f seconds\n", end_time - start_time);

    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < SIZE; i++) {
        result[i] = array1[i] + array2[i];
    }
    end_time = omp_get_wtime();
    printf("Time taken for parallel addition: %f seconds\n", end_time - start_time);

    free(array1);
    free(array2);
    free(result);

    return 0;
}

