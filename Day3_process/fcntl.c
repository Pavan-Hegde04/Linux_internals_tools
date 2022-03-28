#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd1,fd2,fd3;
	fd1=open("fcntl.txt",O_WRONLY|O_CREAT|O_TRUNC,777);
	fd3=fcntl(fd1,F_DUPFD);
	printf("fd3_duplicate of fd1=%d\n",fd3);
	close(fd3);
	close(fd1);
	return 0;
}

