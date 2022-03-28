#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid;
	printf("current process pid = %d\n",getpid());
	pid=fork();
	if(pid==0)
	{
		printf("new child process pid = %d\n",getpid());
		printf("new child parent process ppid = %d\n",getppid());
	}
	else
	{
		printf("parent process pid = %d\n",getpid());
                printf("parents parent process ppid = %d\n",getppid());
	}
	while(1)	
		return 0;
}
