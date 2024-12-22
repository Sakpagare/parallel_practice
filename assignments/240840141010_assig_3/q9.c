//9.WAP to demonstrate time measurement of a particular section of code
#include <stdio.h>
#include <omp.h>

int main() {
    int n, i;
    long long sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    double start_time, end_time;

    start_time = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
    for (i = 1; i <= n; i++) {
        sum += i;
    }
    end_time = omp_get_wtime();

    printf("The sum of the first %d natural numbers is %lld.\n", n, sum);
    printf("Time taken: %f seconds\n", end_time - start_time);

    return 0;
}

