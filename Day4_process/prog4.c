#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int pid,status;
	printf("parent : %d\n",getpid());
	pid=fork();
	if(pid==0)
	{
		printf("I am child pid = %d\n",getpid());
		sleep(5);
		exit(0);
	}
	printf("parent reporting exit of child whose pid = %d\n",waitpid(pid,&status,0));
	return 0;
}
