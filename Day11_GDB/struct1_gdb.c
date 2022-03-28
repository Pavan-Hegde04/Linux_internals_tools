#include<stdio.h>
#include<string.h>
struct student
{
	int roll;
	char name[40],gender __attribute__((aligned(1)));
	float height;\
	char h;
}__attribute__((packed));

int main()
{
	struct student first;
	
	printf("\n size of structure is %3d\n",sizeof(first));
	return 0;
}
