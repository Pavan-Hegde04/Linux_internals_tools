#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Statement1\n");
	fork();
	fork();
	printf("\nstatement2\n");
	while(1)
	{
		return 0;
	}
}

