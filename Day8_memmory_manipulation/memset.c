#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	const char str[]="Linuxkernel.com";
	const char ch='#';
	//char *ret;
	
	printf("String before set/initialization is %s\n",str);
	memset(str,ch,strlen(str));
	printf("String after set is %s\n",str);
	return 0;
}
