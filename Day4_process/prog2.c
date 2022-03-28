#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		sleep(5);
		printf("I am child with delay of 5 sec & my child pid = %d\n",getpid());
	}
	else	
	{
		int pid1;
		printf("I am parent pid = %d\n",getpid());
		pid1=wait(0);
		printf("parent saying ....child%d exited/terminated normally\n",pid1);
		printf("I am parent process pid = %d\n",getpid());
	}
	return 0;
}
