//6.WAP to calculate sum of natural numbers and avoid race condition.


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

    #pragma omp parallel for reduction(+:sum)
    for (i = 1; i <= n; i++) {
        sum += i;
    }

    printf("The sum of the first %d natural numbers is %lld.\n", n, sum);

    return 0;
}

