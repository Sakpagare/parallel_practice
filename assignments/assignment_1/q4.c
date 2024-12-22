#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#define N 20
void* task1(){
	printf("start first task\n");
	sleep(2);
	printf("end first task\n");
}

void* task2(){
	printf("start second task\n");
	sleep(2);
	printf("end second task\n");
}


int main(){
	pthread_t t1[N];
	for(int i=0;i<N;i++){
		if(i<N/2)
			pthread_create(&t1[i],NULL,task1,NULL);
		else
			pthread_create(&t1[i],NULL,task2,NULL);

	}

	for(int i=0;i<N;i++){
		pthread_join(t1[i],NULL);
	}
	return 0;
}
