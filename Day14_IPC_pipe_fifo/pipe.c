#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int fd[2];
	int result;
	char *buff1="Pavan Hegde";
	char *buff2="Linux Kernel";
	char buff3[40];
	
	result=pipe(fd);
	
	if(result==-1)
	{
		perror("Pipe");
		exit(1);
	}
	write(fd[1],buff1,11);
	write(fd[1],buff2,12);
	read(fd[0],buff3,23);
	for(int i=0;i<23;i++)
	{
		printf("%c",buff3[i]);
		//printf("\n");
	}
	printf("\n");
	return 0;
}
