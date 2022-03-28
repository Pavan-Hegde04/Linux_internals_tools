//using pointer after free()

#include<stdio.h>
#include<stdlib.h>

//extern int EF_PROTECT_BELOW;

void buggy(int *p)
{
	p[0]=10;
	free(p);
}

int main()
{
	int *ptr;
	ptr=(int *)malloc(4);
	buggy(ptr);
	free(ptr);
	return 0;
}


