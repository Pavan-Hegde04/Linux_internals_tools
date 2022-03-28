#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	int x;
	x=execl("/usr/bin/vi","vim","info.txt",NULL);
	if(x==-1)
		printf("error creating file %d\n",x);
	else
		printf("Opening new info.txt\n");
	return 0;
}
