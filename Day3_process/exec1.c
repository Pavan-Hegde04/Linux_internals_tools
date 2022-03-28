#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("executing 'vfork' program\n");
	execl("/home/pavan/Training/Linux_internals_tools/Day3","./vfork",0);
	printf("i is executed ls program\n");
	printf("i is executed ls program\n");
	printf("i is executed ls program\n");
	return 0;
}
