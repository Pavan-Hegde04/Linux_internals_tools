//using pointer after free()

#include<stdio.h>
#include<stdlib.h>

//extern int EF_PROTECT_BELOW;

int main()
{
	int *ptr;
	int *ptr1;
	int *ptr2;
	ptr=NULL;
	//ptr1=NULL;
	ptr2=NULL;
	printf("value i: %d\n",*ptr);
	printf("value i: %d\n",*ptr1);
	return 0;
}

