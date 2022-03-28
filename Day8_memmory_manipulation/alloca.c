#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *str1="Linux";
	char *str2="Kernel";
	char *name=(char *)alloca(strlen(str1)+strlen(str2)+1);
	strcpy(stpcpy(name,str1),str2);
	printf("the copied string data is %s\n",name);
	return 0;
}
