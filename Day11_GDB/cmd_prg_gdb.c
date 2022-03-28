#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int i;
	printf("\nFile name: %s\n",argv[0]);//a.out
	printf("\nTotal number of arguments: %d",argc);
	printf("\nArgumnets passed: ");
	for(i=1;i<argc;i++)
		printf("%s ",argv[i]);
	printf("\n");
}
