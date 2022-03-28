#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int pid,pid1;
	printf("current process id = %d\n",getpid());
	pid=fork();
	if(pid)
	{
		printf("parent process id = %d\n",getpid());
		pid1=fork();
		if(pid1)
		{
			printf("new fork parent process id = %d\n",getpid());
		}
		else
		{
			printf("new fork child process id = %d\n",getpid());
		}
	}
	else
	{
		printf("child process id = %d\n",getpid());
	}
	exit(0);
	return 0;
}
