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
	
	printf("opening the file....\n");
	fd=open("myfifo",O_RDONLY);  //open fifo for read only
	printf("Opened the file....\n");
	
	read(fd,S,sizeof(S));   //read data to fifo
	printf("Data you entered is : %s\n",S);
	return 0;
}
