#include<pthread.h>
#include<stdio.h>

pthread_t thid1,thid2;

void *thread1(void *arg)
{
	printf("newly created thread is executing\n");
	return NULL;
}

void *thread2(void *arg)
{
	int a;
	scanf("%d",&a);
	printf("a= %d\n",a);
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
		printf("thread is created\n");
		//sleep(2);
		pthread_join(thid1,NULL);
		pthread_join(thid2,NULL);
	}
	return 0;
}
