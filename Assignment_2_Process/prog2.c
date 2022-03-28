#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd;
	fd=open("execl.c",O_RDONLY,777);
	printf("fd for execl is = %d\n",fd);
	close(fd);
	return 0;
}
