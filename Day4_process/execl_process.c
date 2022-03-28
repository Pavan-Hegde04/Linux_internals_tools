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
	//execl("/home/pavan/Training/Linux_internals_tools/Day3","./ev","linux","kernel","programming","device","drivers",0);
	printf("\n Arguments passed: ");
	for(i=1;i<argc;i++)
	{
		printf("%s",argv[i]);
	}
	printf("\n");
	//execl("/home/pavan/Training/Linux_internals_tools/Day3","./ev","linux","kernel","programming","device","drivers",0);
	return 0;
}
