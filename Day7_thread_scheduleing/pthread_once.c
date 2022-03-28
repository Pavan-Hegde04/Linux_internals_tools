#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

pthread_once_t once= PTHREAD_ONCE_INIT;

void *myinit()
{
	printf("\n I am init function\n");
}

void *mythread(void *i)
{
	printf("\n I am in mythread : %d\n",(int *)i);
	pthread_once(&once,(void *)myinit);
	sleep(2);
	printf("\n Exit from my thread: %d\n",(int *)i);
}
int main()
{
	pthread_t thread,thread1,thread2;
	pthread_create(&thread,NULL,mythread,(void *)1);
	sleep(2);
	pthread_create(&thread1,NULL,mythread,(void *)2);
	sleep(2);
	pthread_create(&thread2,NULL,mythread,(void *)3);
	printf("\n Exit for main Thread\n");
	pthread_exit(NULL);
	return 0;
}
