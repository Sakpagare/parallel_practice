#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 10000  
#define T 4      

int arr[N];

void *init_array(void *arg) {
    int thread_id = *(int *)arg;
    int chunk_size = N / T;
    int start = thread_id * chunk_size;
    int end = (thread_id + 1) * chunk_size;

    if (thread_id == T - 1) {
        end = N;
    }

    for (int i = start; i < end; ++i) {
        arr[i] = i + 1;
    }

}

int main() {
    pthread_t threads[T];
    pthread_attr_t attr;
    int thread_args[T];

    
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    
    for (int i = 0; i < T; ++i) {
        thread_args[i] = i;
        pthread_create(&threads[i], &attr, init_array, (void *)&thread_args[i]);
    }

    
    pthread_attr_destroy(&attr);

    pthread_exit(0);
    printf("Array initialization using detached threads...\n");

    printf("Initialized array elements:\n");
    for (int i = 0; i < 100; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
