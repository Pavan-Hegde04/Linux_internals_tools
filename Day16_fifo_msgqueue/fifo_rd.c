#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main() 
{
	int fd;
	mkfifo("newf",0755);
	char arr1[100],arr2[100];
	while(1)
	{
		fd = open("newf", O_WRONLY);
		fgets(arr2,100,stdin);



		write(fd,arr2,strlen(arr2)+1);
		close(fd);



		fd = open("newf", O_RDONLY);
		read(fd,arr1,sizeof(arr1));
		printf("U 2: %s\n",arr1);
		close(fd);
	}
	return 0;
}

