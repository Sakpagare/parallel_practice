// 3.WAP to create N number of threads

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#define N 10

void* task(){
	printf("start task\n");
	sleep(5);
	printf("end task\n");
}

int main(){
	pthread_t t[N];
        for(int i =0;i<N;i++){
		pthread_create(&t[i],NULL,task,NULL);
	}
         
        for(int i=0;i<N;i++){
		pthread_join(t[i],NULL);
	}
        return 0;
}
