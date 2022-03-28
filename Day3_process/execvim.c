#include<stdio.h>
#include<unistd.h>

int main()
{
	int x;
	x=execl("/usr/bin/vi","vim","info.txt",0);
	if(x==-1)
		printf("error creating file %d\n",x);
	return 0;
}
