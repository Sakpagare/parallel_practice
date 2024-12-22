//2.Implementation of reduction in pthread(alternative)


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define N 10000
#define T 10

long globalArraySum[T];
int arr[N];

void *hello(void* threadId){
	long tid = (long)threadId;
	long localsum =0;
	int chunk_size = N / T;
	int start = tid * chunk_size;
	int end = (tid + 1) * chunk_size;
	if(tid == T - 1){
		end = N;
	}
	for(int i = start;i < end; i++){
		localsum += (long)arr[i];
	}
	globalArraySum[tid] = localsum;
	return NULL;
}


int main(){
	for(int i=0;i<N;i++){
		arr[i] = i + 1;
	}
	pthread_t* t;
	t = malloc(sizeof(pthread_t) * N);

	for(long i = 0;i<T;i++)
		pthread_create(&t[i],NULL,hello,(void*)i);
	for(long i=0;i<T;i++)
		pthread_join(t[i],NULL);
	long sum =0;
	for(int i =0;i<T;i++){
		sum += globalArraySum[i];
	}
	for(int i=0;i<T;i++) printf("local sum of thread %d = %ld\n",i,globalArraySum[i]);
	printf("sum using manual reduction: %ld\n",sum);
	printf("Natural number sum original : %ld\n",((N * ((N + 1) * 1L)) / 2 ));
	free(t);
	return 0;
}
