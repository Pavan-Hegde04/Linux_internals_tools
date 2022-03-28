#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd1;
	char buff1[100];
	fd1=open("linux10.txt",O_RDONLY,777);
	if(fd1<0)
		printf("File is not created or opened\n");
	lseek(fd1,0,SEEK_SET);
	read(fd1,buff1,100);
	printf("data is %s\n",buff1);
	int close(int fd1);
	return 0;
}
	
