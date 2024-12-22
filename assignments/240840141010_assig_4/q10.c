//10.Data creation parallely and performing sum over those data.

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100

int main() {
    int i;
    int *array = (int *)malloc(SIZE * sizeof(int));
    int total_sum = 0;

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    #pragma omp parallel
    {
        #pragma omp for
        for (i = 0; i < SIZE; i++) {
            array[i] = i * 2;
        }

        #pragma omp for reduction(+:total_sum)
        for (i = 0; i < SIZE; i++) {
            total_sum += array[i];
        }
    }

    printf("Total sum = %d\n", total_sum);

    free(array);
    return 0;
}

