#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

int sharedvar=5;

void *thread_inc(void *arg)
{
	sharedvar++;
	printf("after increment = %d\n",sharedvar);
}

void *thread_dec(void *arg)
{
	sharedvar--;
	printf("after decrement = %d\n",sharedvar);
}
int main()
{
	pthread_t thread1,thread2;
	//static int x=10;
	
	pthread_create(&thread1,NULL,thread_inc,NULL);
	pthread_create(&thread2,NULL,thread_dec,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	printf("sharedvar = %d\n",sharedvar);
	return 0;
}
