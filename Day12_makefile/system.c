#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char comm[5];
	strcpy(comm,"ls -l");
	
	printf("system() library function uses fork() to create a child process\n");
	printf("child process executes execl() which loads and run new program provided by system() argument\n");
	int x=system(NULL);
	printf("x = %d\n",x);
	return 0;
}
