
#include<stdio.h>
#include<stdlib.h>

//extern int EF_PROTECT_BELOW;

void buggy()
{
	int *intptr;
	//int i;
	intptr=(int *)malloc(sizeof(int)*5);
	
	//printf("MALLOC checking : Addr=%08x and size=%d\n",intptr,sizeof(int)*5);
	
	
		* intptr=100;
		printf("value at ptr intptr = %d\n",(*intptr));
		free(intptr);
		* intptr=99;
		free(intptr);
	
}

int main()
{
	buggy();
	return 0;
}
