#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#define NUM_THREADS 3
int i=0;
void * myfun(void *null)
{
	i++;
	int result=0;
	result=result+i*1000;
	printf("result = %d\n",result);
	pthread_exit(NULL);
}
int main(int argc,int *argv[])
{
	pthread_t thread[NUM_THREADS];
	pthread_attr_t attr;
	//const pthread_attr_t attr1;
	int rc,t,status,detach_state;
	pthread_attr_init(&attr);
	
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	//pthread_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	for(t=0;t<NUM_THREADS;t++)
	{
		printf("creating thread\n",t);
		pthread_create(&thread[t],&attr,myfun,NULL);
	}
	pthread_attr_getdetachstate(&attr,&detach_state);
	printf("\n detach state : %d\n",(int *)detach_state);
	//pthread_attr_destroy(&attr);
	printf("\n Exiting from main thread\n");
	pthread_exit(NULL);
	return 0;
}
