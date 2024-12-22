//7. perform manual reduction to calculate sum of natural numbers

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

    long long partial_sum = 0;

    #pragma omp parallel private(partial_sum)
    {
        partial_sum = 0;
        #pragma omp for
        for (i = 1; i <= n; i++) {
            partial_sum += i;
        }
        #pragma omp critical
        sum += partial_sum;
    }

    printf("The sum of the first %d natural numbers is %lld.\n", n, sum);

    return 0;
}

