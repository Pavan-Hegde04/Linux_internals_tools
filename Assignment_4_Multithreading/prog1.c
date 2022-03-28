#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

static void *threadfunc(void *arg)
{
	printf("Thread Executing after main() is terminated\n");
	char *s=(char *)arg;
	printf("%s\n",s);
	sleep(5);
	printf("Thread Executed after main() is terminated\n");
	return (void *)strlen(s);
	//return 0;
}

int main(int argc,char *argv[])
{
	pthread_t t1;
	void *res;
	int s;
	s=pthread_create(&t1,NULL,threadfunc,"Hello World");
	printf("Executing main() Function\n");
	sleep(3);
	//pthread_join(t1,&res);
	pthread_exit(NULL);
	//printf("Thread Executed after main() is terminated");
	exit(0);
	return 0;
}
