#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_t thread;

void *threadfunc(void *threadid)
{
	printf("\nHello World\n");
	while(1);
}

int main()
{
	pthread_t thread;
	int t=0;
	printf("creating thread\n");
	pthread_create(&thread,NULL,threadfunc,NULL);
	printf("\n thread id : %lu",thread);
	sleep(5);
	t=pthread_cancel(thread);
	if(t==0)
		printf("\n cancel thread\n");
	printf("\n thread id : %lu\n",thread);
	return 0;
}
