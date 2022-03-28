#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buff1[10];
	char buff2[10];
	int ret;
	
	memcpy(buff1,"madam",5);
	memcpy(buff2,"mad",5);
	
	ret=memcmp(buff1,buff2,5);
	
	if(ret>0)
	{	
		printf("buff1 is greaterthan buff2\n");
		printf("ret = %d\n",ret);
	}
	else if(ret<0)
	{
		printf("buff1 is lessthan buff2\n");
		printf("ret = %d\n",ret);
	}
	else
	{
		printf("buff1 is equal to buff2\n");
		printf("ret = %d\n",ret);
	}
	return 0;
}
