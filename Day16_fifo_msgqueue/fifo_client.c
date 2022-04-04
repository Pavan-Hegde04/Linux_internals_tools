#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	printf("Client is Writing...\n");
	char clientmsg[]="Linux Sysytem Kernel Programming \n  In IPC(Inter process communication) FIFO is going on \n and FIFO is connection Oriented Programming";
	
	//open fifo for write
	int fd=open("Info_FIFO",O_WRONLY);
	if(fd==-1)
	{
		perror("Cannot open File in WRONLY operation...\n");
		return EXIT_FAILURE;
	}
	
	write(fd,clientmsg,strlen(clientmsg));
	
	close(fd);
	return 0;
}
