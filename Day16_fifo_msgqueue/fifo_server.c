#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	printf("Server is waiting .....\n");
	
	//create fifo
	int x=mkfifo("Info_FIFO",0764);
	if(x==-1)
	{
		perror("File is already exist....make with new file name!!\n");
	}
	
	//open read end
	int fd=open("Info_FIFO",O_RDONLY);
	if(fd==-1)
	{
		perror("Cannot open File in RDONLY operation...\n");
		return 0;
	}
	printf("FIFO is Opening ...\n");
	
	//read string(upto 100 characters)
	char serverget[1000];   //string buffer
	memset(serverget,0,1000);  //set server buff with zeros
	
	int result;
	char length;
	while(1)
	{
		result=read(fd,&length,1);
		if(result==0)
		{
			break;
		}
		read(fd,serverget,length);
		//serverget[(int)length]=0;
		printf("Server is getting :  %s\n",serverget);
	}
	
	printf("\nreached upto EOF (End Of File)\n");
	
	close(fd);
	
	printf("FIFO is closing ...\n");
	return 0;
}
