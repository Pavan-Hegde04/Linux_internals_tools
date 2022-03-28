#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd,fd1;
	char buff[20];
	fd=open("file.txt",O_RDONLY,777);
	read(fd,buff,20);
	fd1=open("file2.txt",O_CREAT | O_RDWR,777);
	write(fd1,buff,20);
	close(fd);
	close(fd1);
	return 0;
}
