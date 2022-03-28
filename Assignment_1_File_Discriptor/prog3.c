
	//  ls -l kind of information through an pg using stat();
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main( )
{
	struct stat st;// st.st_size   st.st_ino  st_blksize
	int fd;
	stat("seek.txt", &st);
	printf("File size =%lu\n",(st.st_size));// ls  -l  p3.c
	
	printf("File inode =%lu \n", st.st_ino);// ls -i P3.c
	
	printf("size disc of blocks =%lu \n",st.st_blksize);//stat -fc %s  P3.c
	printf("\n\n");
	close(fd);
	return 0;
}
