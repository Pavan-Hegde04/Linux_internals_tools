#include<stdio.h>

int main(int argc,char *argv[])
{
	int i;
	printf("\n file name : %s\n",argv[0]);
	printf("\n total number of arguments : %d\n",argc);
	printf("\n Arguments passed: ");
	for(i=1;i<argc;i++)
	{
		printf("%s",argv[i]);
	}
	printf("\n");
	return 0;
}
