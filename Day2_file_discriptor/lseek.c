#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd;
	char buff1[100]="My name is pavan,byee";
	char buff2[100];
	fd=open("file.txt",O_CREAT | O_RDWR,777);
	printf("fd = %d\n",fd);
	if(fd>0)
	{
		write(fd,buff1,100);
	}
	else
	{
		printf("error not created file.txt\n");
	}
	lseek(fd,3,SEEK_SET);
	read(fd,buff2,100);
	printf("Data is written in file.txt is ---  %s\n",buff2);
	close(fd);
	return 0;
}
