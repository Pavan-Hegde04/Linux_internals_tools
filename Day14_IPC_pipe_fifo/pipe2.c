#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int fd[2];
char *buff1="Pavan Hegde";
char *buff2="Linux Kernel";
char buff3[100];
int n,i;
void parent()
{
	close(fd[1]);
	n=read(fd[0],buff3,100);
	printf("\nNo. of chars read = %d\n",n);
	for(i=0;i<n;i++)
		printf("%c",buff3[i]);
	printf("\n");
	
	printf("End of parent\n");
}

void child()
{
	
	close(fd[0]);
	write(fd[1],buff1,11);
	write(fd[1],buff2,12);
	
	printf("End of child\n");
	exit(0);
}

int main()
{
	int result,i;
	
	pid_t p;
	result=pipe(fd);
	if(result==-1)
	{
		perror("Pipe");
		exit(1);
	}
	p=fork();
	if(p==0)
	{
		child();
	}
	else
	{
		parent();
	}
	return 0;
}
