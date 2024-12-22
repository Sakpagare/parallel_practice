#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define N 100

pthread_mutex_t mutex;

int sum = 0;

void* hello(void* threadId){
	int tid = *(int*)threadId;

	pthread_mutex_lock(&mutex);
	sum += tid;
	pthread_mutex_unlock(&mutex);
	free(threadId);
}

int main(){
	pthread_t* t;
	pthread_mutex_init(&mutex,NULL);
	t = malloc(sizeof(pthread_t) * N);
	for(int i =0;i<N;i++){
		int* a;
		a = malloc(sizeof(int));
		*a = i;
		pthread_create(&t[i],NULL,hello,(void*)a);
	}

	for(int i=0;i<N;i++)
		pthread_join(t[i],NULL);
	free(t);

	pthread_mutex_destroy(&mutex);
	printf("sum = %d\n",sum);
	if(sum + N == (N * ( N + 1) /2)){
		printf("___Passed___\n");
	}else{
		printf("___Failed___\n");
	}
	return 0;
}
