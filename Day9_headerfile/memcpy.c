#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void my_mem_cpy(char *src,char *dst,int c)
{
	int i;
	for(i=0;i<c;i++)
	{
		*dst=*src;
		dst++;
		src++;
	}
}

int main()
{
	const char src[10]="Old string";
	const char dst[10];
	//char *src[10]="Old string";
	//char *dst[10];
	
	my_mem_cpy(src,dst,10);
	printf("dst = %s, \tsrc = %s \n",dst, src);
	
	return 0;
}

