// 6. Create array of size N using N threads
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define N 20
#define T 4

int* arr;
void* hello(void* threadId){
	int tid = *(int*)threadId;
	arr[tid] = tid;
	free(threadId);
}

int main(){
	arr = malloc(sizeof(int) * N);
	pthread_t* t;
	t = malloc(sizeof(pthread_t) * N);
	for(int i = 0; i<N;i++){
		int* a;
		a = malloc(sizeof(int));
		*a = i;
		pthread_create(&t[i],NULL,hello,(void*)a);
	}
	for(int i=0;i<N;i++)
		pthread_join(t[i],NULL);
	free(t);
	for(int i=0;i<N;i++) printf(" %d ",arr[i]);
	printf("\n");
	return 0;
}

