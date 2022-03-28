#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,fd3;
	fd1 = open("linux10.txt",O_RDONLY,777);
	fd2 = open("linux200.txt",O_RDONLY,777);
	fd3 = open("linux30.txt",O_RDONLY,777);
	
	printf("fd for linux10.txt is %d\n",fd1);
	printf("fd for linux200.txt is %d\n",fd2);
	printf("fd for linux30.txt is %d\n",fd3);

	int close(int fd1);
	int close(int fd2);
	int close(int fd3);
	return 0;
}
	
