#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
static void *threadfunc(void *arg)
{
	char *s=(char *)arg;
	printf("%s\n",s);
	sleep(5);
	return (void *)strlen(s);
	//return 0;
}

int main(int argc,char *argv[])
{
	pthread_t t1;
	void *res;
	int s;
	s=pthread_create(&t1,NULL,threadfunc,"Hello World");
	printf("Message from main()\n");
	sleep(3);
	//pthread_join(t1,&res);
	pthread_exit(NULL);
	printf("Thread returned %ld\n",(long)res);
	exit(0);
	return 0;
}
