#include<stdio.h>
#include<signal.h>

void sighand(int signum)
{
	printf("\t SIGINT having signal no. %d that is (ctrl+c) handling in linux internals \n",signum);
	
}

int main()
{
	signal(SIGINT,sighand);
	//alarm(5);
	while(1)
	{
	
	}
	return 0;
}
