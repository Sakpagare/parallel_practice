//8.WAP to demostrate omp barrier

#include <stdio.h>
#include <omp.h>

int main() {
    int i;

    #pragma omp parallel private(i)
    {
        printf("Thread %d: Before barrier\n", omp_get_thread_num());

        #pragma omp barrier

        printf("Thread %d: After barrier\n", omp_get_thread_num());
    }

    return 0;
}

