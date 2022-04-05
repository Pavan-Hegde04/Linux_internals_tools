//this is example demonstrates how to block signals using sigprocmask()
#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

//getpid()

void printsignalset(sigset_t *set)
{
	const int siglist[] = { SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGABRT, SIGFPE, SIGKILL, SIGSEGV };
	
	const char *signames[] = { "SIGHUP", "SIGINT", "SIGQUIT", "SIGILL", "SIGABRT", "SIGFPE", "SIGKILL", "SIGSEGV" };
	
	const int siglen = 8;
	
	for(int i=0;i<siglen;i++)
	{
		int ret = sigismember(set,siglist[i]);
		if(ret==-1)
		{
			perror("sigismember:");
			exit(EXIT_FAILURE);
		}
		else if(ret ==1)
		{
			printf("Signal %s=%d is in the set.\n",signames[i],siglist[i]);
		}
		else
		{
			printf("Signal %s=%d is not in the set.\n",signames[i],siglist[i]);
		}
	}
}

int main()
{
	sigset_t set;
	
	if(sigprocmask(0,NULL,&set)!=0)
	{
		perror("sigprocmask:");
		exit(EXIT_FAILURE);
	}
	
	printf("---Initial signal mask for this process: ---\n");
	printsignalset(&set);
	
	if(sigaddset(&set,SIGINT)!=0)
	{
		perror("sigaddset:");
		exit(EXIT_FAILURE);
	}
	if(sigprocmask(SIG_SETMASK,&set,NULL)!=0)
	{
		perror("sigprocmask:");
		exit(EXIT_FAILURE);
	}
	
	printf("---New signal mask for this process: ---\n");
	printsignalset(&set);
	
	int sectosleep=20;
	printf("Try ctrl+c. Try killing this program with 'kill -kill %d'. Going to sleep for %d seconds. \n",getpid(),sectosleep);
	sleep(sectosleep);
	printf("Sleep returned. \n");
	
	printf("Removing all signals from mask. \n");
	sigfillset(&set);
	sigprocmask(SIG_SETMASK,&set,NULL);
	printsignalset(&set);
	sleep(1);
	printf("Exited normally. \n");
	return 0;
}
