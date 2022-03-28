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
		printf("my child pid = %d\n",getpid());
	}
	else	
	{
		int pid1;
		pid1=wait(0);
		printf("I am parent process pid = %d\n",getpid());
	}
	return 0;
}
