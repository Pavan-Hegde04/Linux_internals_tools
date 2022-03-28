#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	char S[20];
	int fd;
	
	mkfifo("myfifo",0644);  //myfifo is an pipe i.e a file named pipe create fifo(named pipe)
	
	perror("mkfifo");
	
	printf("Opening the file ...\n");
	
	fd=open("myfifo",O_WRONLY);  //open fifo for write only
	
	printf("Opened the file....\n");
	
	printf("Enter the data .... \n");
	scanf("%s",S);
	//gets(S);
	write(fd,S,strlen(S)+1);   //std write(); internally filewrite data to fifo
	return 0;
}
