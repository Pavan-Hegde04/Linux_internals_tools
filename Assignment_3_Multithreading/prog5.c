#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<semaphore.h>

int sharedvar=101;

pthread_mutex_t my_mutex;

void *thread_inc(void *arg)
{
	pthread_mutex_lock(&my_mutex);
	sharedvar++;
	printf("after increment = %d\n",sharedvar);
	pthread_mutex_unlock(&my_mutex);
}

void *thread_dec(void *arg)
{
	pthread_mutex_lock(&my_mutex);
	sharedvar--;
	printf("after decrement = %d\n",sharedvar);
	pthread_mutex_unlock(&my_mutex);
}
int main()
{
	pthread_t thread1,thread2;
	pthread_mutex_init(&my_mutex,NULL);
	//static int x=10;
	
	pthread_create(&thread1,NULL,thread_inc,NULL);
	pthread_create(&thread2,NULL,thread_dec,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	printf("sharedvar = %d\n",sharedvar);
	return 0;
}
