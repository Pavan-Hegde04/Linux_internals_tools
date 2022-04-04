#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

void check_blocked_sigs()
{
	int i,res;
	sigset_t s;
	sigprocmask(SIG_BLOCK,NULL,&s); //first param is not considered
	for(i=1;i<=10;i++)
	{
		res=sigismember(&s,i);
		if(res)
			printf("Signal %d is blocked!!!!! \n",i);
		else
			printf("Signal %d is not blocked.... \n",i);
	}
}

int main()
{
	sigset_t s_set;
	sigemptyset(&s_set);
	sigaddset(&s_set,2);
	sigaddset(&s_set,3);
	sigaddset(&s_set,4);
	sigaddset(&s_set,5);
	sigaddset(&s_set,8);
	sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set,NULL);
	check_blocked_sigs();
	sigprocmask(SIG_UNBLOCK,&s_set,NULL);
	check_blocked_sigs();
	return 0;
}
