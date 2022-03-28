#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>
pthread_spinlock_t spinlock;
volatile int slock;

void *spinlockthread(void *i)
{
	int rc=0;
	int count=0;
	printf("Entered thread %d, getting spin lock \n",(int *)i);
	rc=pthread_spin_lock(&slock);
	printf("%d Thread unlock the spin lock\n",(int *)i);
	return NULL;
}

int main()
{
	int rc=0;
	pthread_t thread1,thread2;
	if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
		perror("init");
	printf("main, get spin lock\n");
	rc=pthread_spin_lock(&slock);
	
	printf("Main, create the spin lock thread\n");
	
	rc=pthread_create(&thread1,NULL,spinlockthread,(int*)1);
	
	printf("Main, wait a bit the spin lock\n");
	sleep(5);
	rc=pthread_spin_unlock(&slock);
	
	if(rc==0)
		printf("\n Main thread successfully unlocked\n");
	else
		printf("\n Main thread unsuccessfully unlocked\n");
	
	printf("Main, wait for the thread to end\n");
	rc=pthread_join(thread1,NULL);
	rc=pthread_spin_destroy(&slock);
	printf("Main completed\n");
	return 0;
}
