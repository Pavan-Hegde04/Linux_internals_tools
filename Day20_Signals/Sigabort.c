#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void abort_handler(int);

int main()
{
	if(signal(SIGABRT,abort_handler)==SIG_ERR)
	{
		fprintf(stderr,"Couldn't set signal handler \n");
		exit(1);
	}
	//signal(SIGINT,SIG_DFL);
	abort();
	exit(0);
	return 0;
}

void abort_handler(int i)
{
	printf("Signal number :  %d \n",i);
	fprintf(stderr, "Caught SIGABRT, exiting application \n");
	exit(1);
}
