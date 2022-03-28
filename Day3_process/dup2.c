#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd1,fd2,fd3;
	fd1=open("linuxx.txt",O_WRONLY|O_CREAT|O_TRUNC,777);
	fd2=open("linuxx1.txt",O_WRONLY|O_CREAT|O_TRUNC,777);
	printf("fd1=%d\n",fd1);
	printf("fd2=%d\n",fd2);
	fd3=dup2(fd1,10);
	printf("fd3_duplicate of fd1=%d\n",fd3);
	close(fd3);
	close(fd2);
	close(fd1);
	return 0;
}

