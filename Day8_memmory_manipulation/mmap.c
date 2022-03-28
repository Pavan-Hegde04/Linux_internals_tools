#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<string.h>

int main()
{
	char *c;
	c=mmap(0,50,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE,-1,0);//msg success
	perror("mmap");
	
	strcpy(c,"Linux Kernel");//kernel region in user space
	printf("%s\n",c);
	//deallocate all resources
	munmap(c,50);//malloc after free
	
	//printf("c=%s\n",c);
	return 0;
}
