#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

void sighand(int no)
{
	printf("calling signal handler...\n");
}
int main()
{
	sigset_t s_set;	//group of signals	
	signal(2,sighand);	//here we are setting SIGINT (ctrl+c) to function sighand.
	sigemptyset(&s_set);	//initializing/clearing the signal set with sigemptyset
	sigaddset(&s_set,2);	//adding signal to structure that is signal no. 2
	perror("Sig2");
	sigaddset(&s_set,4);	//adding signal to structure that is signal no. 4
	perror("Sig4");
	sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set,NULL);	//blocking the no. of signals that is in structure called s_set
	perror("sigmask");
	printf("send me signal one and see the effect \n");
	getchar();
	getchar();
	sigprocmask(SIG_UNBLOCK,&s_set,NULL);		//unblocking the no. of signals that is in structure called s_set
	printf("Now signals are unblocked \n");
	while(1);
	return 0;
}
