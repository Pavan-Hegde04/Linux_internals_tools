#include<stdio.h>
#include"mul.h"

int main()
{
	int x,y,result;
	scanf("%d",&x);
	scanf("%d",&y);
	result=mul(x,y);
	printf("Multiplication of given numbers is %d\n",result);
	return 0;
}
