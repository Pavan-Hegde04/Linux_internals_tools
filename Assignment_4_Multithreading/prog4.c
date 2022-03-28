#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

int main()
{
	pthread_t tid;
	struct sched_param param;
	int priority,policy,result;
	
	//scheduling parameters of target thread
	result=pthread_getschedparam(pthread_self(),&policy,&param);
	printf("Getting policy & priority before setting it\n\n");
	if(result!=0)
		perror("error in getschedparam");
	printf("\n-----------------Main thread--------------\n policy : %d \t priority : %d\n",policy,param.sched_priority);
	printf("Setting policy & priority \n\n");
	policy=SCHED_FIFO;
	param.sched_priority=15;
	result=pthread_setschedparam(pthread_self(),policy,&param);
	if(result!=0)
		perror("error in setschedparam");
	
	
	printf("Getting policy & priority after setting it\n\n");
	result=pthread_getschedparam(pthread_self(),&policy,&param);
	if(result!=0)
		perror("error in getschedparam");
	printf("\n-----------------Main thread--------------\n policy : %d \t priority : %d\n",policy,param.sched_priority);
	
	return 0;
}
