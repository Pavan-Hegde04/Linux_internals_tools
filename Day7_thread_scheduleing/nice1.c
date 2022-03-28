#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main()
{
	int ret,ret1,i,cnt=0,cnt1=0;
	errno=0;
	ret=nice(1);// nice() used to assign nice value to a particular(incr/decr
	ret1=nice(5);// nice() used to assign nice value to a particular(incr/decr
	if(ret==-1 && errno !=0)
		perror("nice");
	else if(ret1==-1 && errno !=0)
		perror("nice1");
	else
		printf("nice value is now %d\n",ret);
	while(cnt==50 && cnt1==50)
	{
		printf("process with nice value %d count = %d\n",ret,cnt);
		for(i=0;i<50;i++);
		cnt++;
		printf("process with nice value %d count = %d\n",ret1,cnt1);
		for(i=0;i<50;i++);
		cnt1++;
	}
	return 0;
}
