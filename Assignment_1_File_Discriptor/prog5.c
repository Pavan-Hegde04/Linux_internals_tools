#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	int fd;
	char buff[]="Hello";
	char buff1[]="Hi";
	fd=creat("prog5.txt",777);
	write(fd,buff,6);
	lseek(fd,4093,SEEK_SET);
	write(fd,buff1,3);
	return 0;
}
