#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int pid,pid1;
	printf("current process id = %d\n",getpid());
	pid=fork();
	while(1){
	if(pid==0)
	{
		printf("child process id 1= %d\n",getpid());
		printf("%d\n",getppid());
		
	}
	else
	{
		pid1=fork();
		if(pid1==0)
		{
			printf("\nchild process id 2= %d\n",getpid());
			printf("%d\n",getppid());
		}
		else
		{
			printf("parent process id = %d\n",getpid());
		}	
	}
	exit(0);
	}
	return 0;
}
