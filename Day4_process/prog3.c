#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	pid=fork();
	if(pid)
	{
		printf("I am parent pid = %d\n",getpid());
		pid=wait(0);
		printf("parent saying ....child%d exited/terminated normally\n",pid);
		printf("I am parent process pid = %d\n",getpid());
	}
	return 0;
}
