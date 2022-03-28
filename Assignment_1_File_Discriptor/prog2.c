#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd,pos,pos1,pos2;
	char buff1[100]="My name is pavan,byee";
	char buff2[100];
	fd=open("seek.txt",O_CREAT | O_RDWR,777);
	printf("fd = %d\n",fd);
	if(fd>0)
	{
		write(fd,buff1,100);
	}
	else
	{
		printf("error not created seek.txt\n");
	}
	pos=lseek(fd,3,SEEK_SET);
	printf("Position using SEEK_SET -- %d\n",pos);
	pos2=lseek(fd,17,SEEK_CUR);
	printf("Position using SEEK_CUR -- %d\n",pos2);
	pos1=lseek(fd,0,SEEK_END);
	printf("Position using SEEK_END -- %d\n",pos1);
	close(fd);
	return 0;
}
