//5. Program to check address of each iteration
#include<stdio.h>
#include<pthread.h>

int main(){
	for(int i=0;i<20;i++){
		printf("%d is located at %p\n",i,&i);
	}
	return 0;
}
