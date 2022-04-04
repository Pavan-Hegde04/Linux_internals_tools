#include<stdio.h>
#include<signal.h>

void sighand(int signum)
{
	printf("I am doing Sigalarm in linux internals \n");
	alarm(5);
}

int main()
{
	signal(SIGALRM,sighand);
	alarm(5);
	while(1)
	{
	
	}
	return 0;
}
