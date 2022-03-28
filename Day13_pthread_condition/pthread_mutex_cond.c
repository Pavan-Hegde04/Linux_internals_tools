#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock = PTHREAD_COND_INITIALIZER;

int done =1;
//thread function
void *foo(void *arg)
{
	char *str=(char *)arg;
	
	printf("thread task called by = %s\n",str);
	//acquire lock
	pthread_mutex_lock(&lock);
	if(done==1)
	{
		//lets wait on condition variable cond1
		//done=2;
		printf("Waiting on condition variable cond1\n");
		pthread_cond_wait(&cond1,&lock);
	}
	else
	{
		//lets signal condition variable cond1
		printf("signaling condition variable cond1\n");
		pthread_cond_signal(&cond1);
	}
	
	//release lock
	pthread_mutex_unlock(&lock);
	
	printf("Returning thread %s\n",str);
	printf("Returning thread %s\n",str);
	return NULL;
}

int main()
{
	pthread_t tid1,tid2;
	//create thread 1
	pthread_create(&tid1,NULL,foo,"Thread One");
	
	//sleep for 1 sec so that thread 1 would get a chance to run first
	sleep(1);
	
	//lets wait on condition variable cond1
	done=2;
	//create thread 2
	pthread_create(&tid2,NULL,foo,"Thread Two");
	//wait for completion of thread 2
	pthread_join(tid2,NULL);
	
	return 0;
}
