#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

int main()
{
	pid_t pid;
	int sig_no;
	printf("Enter pid that have to send signal...");
	scanf("%d",&pid);
	printf("Enter the signal that need to be sent : ");
	scanf("%d",&sig_no);
	kill(pid,sig_no);
	perror("Sig_res:");
	return 0;
}
