#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
void * threadfunc(void *p);
int fd;
int main(void)
{
	pthread_t t1,t2;
	fd=open("/etc/passwd",O_RDONLY);
	printf("File opened with fd : %d\n",fd);
	pthread_create(&t1,NULL,threadfunc,"Thread One");
	pthread_create(&t2,NULL,threadfunc,"Thread Two");
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}


void * threadfunc(void *p)
{
	char *str,buff[100];
	int n,pid;
	str=(char *)p;
	pid=getpid();
	printf("%s: \t Started Now: \t For process %d \n\n",str,pid);
	do
	{
		n=read(fd,buff,100);
		printf("%s: \tRead: \t %d \n\n",str,pid);
		printf("\n-----------------\n");
		write(1,buff,n);

		printf("\n-----------------\n");
		sleep(3);
	}while(n);
	printf("%s: \t Finished: \t For process %d \n\n",str,pid);
}

