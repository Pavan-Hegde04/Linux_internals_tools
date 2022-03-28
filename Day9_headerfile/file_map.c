#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<string.h>

int main()
{
	char *c;
	int fd;
	struct stat file_info;
	fd=open("kernel.txt",O_CREAT|O_RDWR,777);
	//perror("open");
	write(fd,"linux kernel technology",25);
	
	fstat(fd,&file_info);
	//perror("fstat");
	printf("File size is %d\n",file_info.st_size);
	
	c=mmap(0,file_info.st_size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);//msg success
	perror("mmap");
	
	printf("%s\n",c);//no need of accessing system call for file read write
	
	//deallocating all resources
	munmap(c,file_info.st_size);
	close(fd);
	
	return 0;
}
