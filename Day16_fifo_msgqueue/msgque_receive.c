#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

struct my_msg_queue
{
	long my_type;
	char data[1024];
};

int main(int argc,char **argv)
{
	struct my_msg_queue mq;
	int id;
	
	if(argc!=2)
	{
		printf("usage: ./msgque_receive type \n");
		printf("Example: msgque_receive 5 \n");
		return 0;
	}
	id=msgget(100,IPC_CREAT|0644);
	if(id<0)
	{
		perror("msgget");
		return 0;
	}
	
	msgrcv(id,&mq,sizeof(mq),atoi(argv[1]),0);
	
	printf("Data : %s\n",mq.data);
	return 0;
}
