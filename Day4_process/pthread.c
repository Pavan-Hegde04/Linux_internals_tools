#include<pthread.h>
#include<stdio.h>

pthread_t thid;

void *thread1(void *arg)
{
	printf("newly created thread is executing\n");
	return NULL;
}

int main(void)
{
	int ret=pthread_create(&thid,NULL,thread1,NULL);
	if(ret)
		printf("thread is not created\n");
	else
		printf("thread is created\n");
		//sleep(2);
		pthread_join(thid,NULL);
	return 0;
}
