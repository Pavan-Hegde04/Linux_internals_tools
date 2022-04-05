#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<unistd.h>

int fd[2];

void toggle(char *buf,int count)
{
	int x;
	for(x=0;x<count;x++)
	{
		if((buf[x]>='A')&&(buf[x]<='Z'))
		{
			buf[x]+=0x20;
		}
		else if((buf[x]>='a')&&(buf[x]<='z'))
		{
			buf[x]-=0x20;
		}
	}
}

void parent()
{
	char *buff1="pavan hegde";
	char *buff2="linux kernel";
	close(fd[0]);
	write(fd[1],buff1,11);
	write(fd[1],buff2,12);
	printf("End of parent\n");
}

void child()
{
	char buff3[100];
	int n,i;
	close(fd[1]);
	n=read(fd[0],buff3,100);
	printf("\nNo. of chars read = %d\n",n);
	for(i=0;i<n;i++)
		printf("%c",buff3[i]);
	printf("\n");
	printf("... Toggling message ...\n");
	toggle(buff3,strlen(buff3));
	for(i=0;i<n;i++)
		printf("%c",buff3[i]);
	printf("\n");
	printf("End of child\n");
	exit(0);
}


int main()
{
	int res,i;
	
	pid_t p;
	res=pipe(fd);
	if(res==-1)
	{
		perror("Pipe");
		exit(1);
	}
	p=fork();
	if(p==0)
	{
		printf("I am executing parent() so i am writing in buffer..\n");
		parent();
	}
	else
	{
		printf("\nI am executing child() so i am reading from buffer..");
		child();
	}
	return 0;
}
