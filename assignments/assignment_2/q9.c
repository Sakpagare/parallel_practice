#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

// Shared data structure to hold data created by threads
char *data_storage[NUM_THREADS];

// Thread function to create data
void *data_creator(void *arg) {
    int thread_id = *(int *)arg;
    printf("Thread-%d is creating data...\n", thread_id);

    // Simulate work with sleep
    sleep(1);

    // Allocate and create data for this thread
    char *data = (char *)malloc(50 * sizeof(char));
    sprintf(data, "Data_from_Thread_%d", thread_id);

    // Store data in shared storage
    data_storage[thread_id] = data;
    printf("Thread-%d has created data: %s\n", thread_id, data);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the shared data storage
    for (int i = 0; i < NUM_THREADS; i++) {
        data_storage[i] = NULL;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, data_creator, (void *)&thread_ids[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print final data storage
    printf("\nFinal Data Storage:\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        if (data_storage[i] != NULL) {
            printf("Thread-%d: %s\n", i, data_storage[i]);
            free(data_storage[i]); // Free allocated memory
        }
    }

    return 0;
}

