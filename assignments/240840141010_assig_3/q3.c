// 3.WAP to demonstrate shared
#include<stdio.h>
#include<omp.h>

int main(){
	int a = 5;
	int b = 24;
#pragma omp parallel shared(a) num_threads(4)
	{
		printf("Inside: a = %d by tid %d : %p \n",a,omp_get_thread_num(),&a);
		b = 234;
	}
	printf("after : a = %d : %p\n",a,&a);
	return 0;
}
