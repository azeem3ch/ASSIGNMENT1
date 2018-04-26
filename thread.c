#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void* sum1(void *);

int main()
{
	pthread_t thread[10];
	int i=0;
	for(; i<10; i++)
		pthread_create(&thread[i],NULL,sum1,(void*)(i*100));
	
	int total=0,*temp,j=0;
	for(; j<10; j++)
	{
		pthread_join(thread[j],(int*)&temp);
		total+=(int)temp;
	}
	printf("sum of first 1000 integers is %d \n",total);

}
void* sum1(void* j)
{
	int a=(int)j,sum=0;
	int i=a;

	for(; i<a+100; i++)
		sum+=i;

	return (void*)sum;
}
