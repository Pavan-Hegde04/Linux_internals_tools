#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd1;
	char buff[100]="Hello how are you?, myself pavan";
	fd1 = open("linux10.txt",O_CREAT | O_RDWR,777);
	
	printf("fd for linux10.txt is %d\n",fd1);
	
	write(fd1,buff,100);

	int close(int fd1);
	return 0;
}
	
