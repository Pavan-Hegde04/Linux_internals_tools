#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

void check_pending_sigs(sigset_t s)
{
	int i,res;
	
	for(i=1;i<=5;i++)
	{
		res=sigismember(&s,i);
		if(res)
			printf("Signal %d is pending!!!!! \n",i);
		else
			printf("Signal %d is not pending.... \n",i);
	}
}

void sighand(int no)
{
	printf("calling signal handler...\n");
}

int main()
{
	sigset_t s_set,s;	//group of signals	
	signal(2,sighand);	//here we are setting SIGINT (ctrl+c) to function sighand.
	sigemptyset(&s_set);	//initializing/clearing the signal set with sigemptyset
	sigaddset(&s_set,2);	//adding signal to structure that is signal no. 2
	perror("Sig2");
	sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set,NULL);	//blocking the no. of signals that is in structure called s_set
	perror("sigmask");
	printf("send me signal one and see the effect \n");
	getchar();
	getchar();
	sigpending(&s);
	check_pending_sigs(s);
	getchar();
	sigprocmask(SIG_UNBLOCK,&s_set,NULL);		//unblocking the no. of signals that is in structure called s_set
	printf("Now signals are unblocked \n");
	while(1);
	return 0;
}
