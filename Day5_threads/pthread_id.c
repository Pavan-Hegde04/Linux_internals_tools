#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t tid;

static void *threadfunc(void *arg)
{
	pid_t pid;
	pthread_t tid;
	pid=getpid();
	tid=pthread_self();
	printf("pid : %u\n tid : %u\n",(unsigned int)pid,(unsigned int)tid);
	return 0;
}

int main(void)
{
	int err;
	err=pthread_create(&tid,NULL,threadfunc,NULL);
	if(err!=0)
		printf("can't create thread : %d\n", strerror(err));
	while(1);
	pthread_join(tid,NULL);
	exit(0);
	return 0;
}
