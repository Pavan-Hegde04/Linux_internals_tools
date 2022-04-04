#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

void sig_handler(int signum)
{
	printf(" Calling signal handler...\n");
}

int main()
{
	pid_t pid;
	signal(SIGUSR1,sig_handler);  //register signal handler
	printf(" Inside main() ...\n");
	pid=getpid();  //process id itself
	printf(" Pid = %d \n",pid);
	kill(pid,SIGUSR1);  //send SIGUSR1 to itself
	printf(" Inside main() ....\n");
	
	return 0;
}
