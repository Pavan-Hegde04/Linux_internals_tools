#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

void *my(void *i)
{
	printf("\nI am in %d Thread \n",(int *)i);
}
int main()
{
	pthread_t tid;
	struct sched_param param;
	int priority,policy,ret;
	//scheduling parameters of target thread
	ret=pthread_getschedparam(pthread_self(),&policy,&param);
	if(ret!=0)
		perror("getschedparam");
	printf("\n-----------------Main thread--------------\n policy : %d \t priority : %d\n",policy,param.sched_priority);
	policy=SCHED_FIFO;
	param.sched_priority=5;
	ret=pthread_setschedparam(pthread_self(),policy,&param);
	if(ret!=0)
		perror("getschedparam");
	//policy=0;
	//param.sched_priority=0;
	ret=pthread_getschedparam(pthread_self(),&policy,&param);
	if(ret!=0)
		perror("getschedparam");
	printf("\n-----------------Main thread--------------\n policy : %d \t priority : %d\n",policy,param.sched_priority);
	
	return 0;
}
