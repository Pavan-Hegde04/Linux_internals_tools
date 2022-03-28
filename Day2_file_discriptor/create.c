#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,fd3;
	fd1 = creat("linux10.txt",777);
	fd2 = creat("linux20.txt",777);
	fd3 = creat("linux30.txt",777);
	
	printf("fd for linux10.txt is %d\n",fd1);
	printf("fd for linux20.txt is %d\n",fd2);
	printf("fd for linux30.txt is %d\n",fd3);

	int close(int fd1);
	int close(int fd2);
	int close(int fd3);
	return 0;
}
	
