#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>

int main()
{
	int fd;
	char buff1[100]="My name is pavan,byee";
	char buff2[100];
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		sleep(5);
		printf("I am child with delay of 5 sec & my child pid = %d\n",getpid());
		fd=open("seek_set.txt",O_CREAT | O_RDWR,777);
		printf("fd = %d\n",fd);
		if(fd>0)
		{
			write(fd,buff1,100);
		}
		else
		{
			printf("error not created seek_set.txt\n");
		}
		lseek(fd,0,SEEK_SET);
		read(fd,buff2,100);
		printf("Data is written in seek_set.txt is ---  %s\n",buff2);
	}
	else	
	{
		wait(0);
		printf("I am parent process pid = %d\n",getpid());
	}
	return 0;
}
