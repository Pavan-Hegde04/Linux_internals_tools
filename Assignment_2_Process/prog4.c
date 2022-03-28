#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
	int i;
	printf("\n file name : %s\n",argv[0]);
	printf("\n total number of arguments : %d\n",argc);
	execl("prog1","./prog1","linux","kernel","programming","device","drivers",NULL);
	printf("\n Arguments passed: ");
	for(i=1;i<argc;i++)
	{
		printf("%s",argv[i]);
	}
	printf("\n");
	
	return 0;
}
