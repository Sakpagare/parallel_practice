#include<stdio.h>
#include<omp.h>

int main(){
	int i,sum=0;
	int thread_sum[4];
	omp_set_num_threads(4);
#pragma omp parallel
	{
		int id = omp_get_thread_num();
		thread_sum[id] = 0;
#pragma omp for
		for(i =1;i<=100;i++)
		{
			thread_sum[id] +=i;
		}
	}
	for(i =0;i<4;i++){
		sum +=thread_sum[i];
	}
	printf("sum = %d\n",sum);

	return 0;
}
