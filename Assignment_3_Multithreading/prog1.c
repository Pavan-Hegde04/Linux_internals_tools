#include<pthread.h>
#include<stdio.h>

pthread_t thid1,thid2;
int var;

void *thread1(void *arg)
{
	printf("created thread 1 is executing\n");
	//printf("Assign value to global variable\n");
	scanf("%d",&var);
	printf("Assigning value to global variable var= %d\n",var);
	return NULL;
}

void *thread2(void *arg)
{
	printf("created thread 2 is executing\n");
	//printf("Assign value to global variable\n");
	scanf("%d",&var);
	printf("Assigning value to global variable var= %d\n",var);
	return NULL;
}

int main(void)
{
	int ret=pthread_create(&thid1,NULL,thread1,NULL);
	int ret1=pthread_create(&thid2,NULL,thread2,NULL);
	if(ret)
		printf("thread 1 is not created\n");
	else if(ret1)
		printf("thread 2 is not createdn");
	else
	{
		printf("threads are created\n");
		
		pthread_join(thid2,NULL);
		pthread_join(thid1,NULL);
	}
	return 0;
}
