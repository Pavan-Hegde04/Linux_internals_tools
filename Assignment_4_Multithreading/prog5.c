#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>
pthread_spinlock_t spinlock;
volatile int lock;

void *spinlockthread(void *i)
{
	int p=0;
	int count=0;
	printf("Entered in thread %d, implementing spin-lock \n",(int *)i);
	p=pthread_spin_lock(&lock);
	printf("Thread %d unlocked the spin-lock\n",(int *)i);
	return NULL;
}

int main()
{
	int p=0;
	pthread_t thread1,thread2;
	if(pthread_spin_init(&lock,PTHREAD_PROCESS_PRIVATE)!=0)
		perror("init");
	printf("main, implement spin-lock to thread\n");
	p=pthread_spin_lock(&lock);
	
	printf("Main, implementing the spin-lock thread\n");
	
	p=pthread_create(&thread1,NULL,spinlockthread,(int*)1);
	
	//printf("Main, wait a bit the spin lock\n");
	sleep(5);
	p=pthread_spin_unlock(&lock);
	
	if(p==0)
		printf("\n Main thread successfully unlocked\n");
	else
		printf("\n Main thread unsuccessfully unlocked\n");
	
	printf("I am in Main, waiting for the thread to end\n");
	p=pthread_join(thread1,NULL);
	p=pthread_spin_destroy(&lock);
	return 0;
}
