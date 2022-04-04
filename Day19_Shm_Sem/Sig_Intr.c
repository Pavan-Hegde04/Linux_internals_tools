#include<stdio.h>
#include<signal.h>

void sig_handler(int signum)
{
	printf("Interupt signal ctrl+c is not terminating.....\n");
	signal(SIGINT,SIG_DFL);
}

int main()
{
	int i;
	signal(SIGINT,sig_handler);
	//signal(SIGINT,SIG_DFL);
	//while(1){}
	
	for(i=0;;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
	//signal(SIGINT,SIG_DFL);
}
