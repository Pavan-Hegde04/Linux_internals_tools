#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char dest[10]="Old str";
	char src[10]="New str";
	//int ret;
	
	
	printf("before memmove dest = %s, src = %s \n",dest, src);
	memmove(dest,src,9);
	printf("after memmove dest = %s, src = %s \n",dest, src);
	//printf("ret = %d\n",ret);
	
	return 0;
}
