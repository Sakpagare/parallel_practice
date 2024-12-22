// 2. WAP to create 2 threads

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void* task1(){
	printf("start task1\n");
	sleep(2);
	printf("end task1\n");

}

void* task2(){
	printf("start task2\n");
	sleep(2);
	printf("end task2\n");
}

int main(){
	pthread_t t1,t2;
	pthread_create(&t1,NULL,task1,NULL);
	pthread_create(&t2,NULL,task2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
