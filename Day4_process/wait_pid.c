#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int pid,pid1;
	printf("current process id = %d\n",getpid());
	pid=fork();
	if(pid)
	{
		wait(0);
		printf("parent process id = %d\n",getpid());
		
	}
	else
	{
		printf("child process id = %d\n",getpid());
		printf("executing 'ls' program in child pid\n");
		execl("/bin/ls","ls","-l",0);
		exit(0);
		printf("i is executed ls program\n");
	}
	exit(0);
	return 0;
}
