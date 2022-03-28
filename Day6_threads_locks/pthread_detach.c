#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

void * process(void *arg)
{
	pthread_detach(pthread_self());
	printf("sleeping 2 secs\n");
	sleep(2);
	printf("slept 2 secs\n");
	//pthread_exit(NULL);
}
int main()
{
	pthread_t thread;
	int errno=pthread_create(&thread,NULL,process,NULL);
	if(errno)
		perror("pthread_create: ");
	pthread_exit(NULL);
	return 0;
}
