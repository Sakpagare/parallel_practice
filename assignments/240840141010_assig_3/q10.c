//10. WAP to measure time taken by parallel and serial array addition in same code.



#include <stdio.h>
#include <omp.h>

#define SIZE 1000

int main() {
    int i;
    double start_time, end_time;
    int array1[SIZE], array2[SIZE], result[SIZE];

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

    // Parallel addition
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < SIZE; i++) {
        result[i] = array1[i] + array2[i];
    }
    end_time = omp_get_wtime();
    printf("Time taken for parallel addition: %f seconds\n", end_time - start_time);

    return 0;
}

