#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

#define KEY 8979

struct my_msg_queue
{
	long my_type;
	char data[1024];
};

int main(int argc,char **argv)
{
	struct my_msg_queue mq;
	struct msqid_ds buff;
	int id;
	
	if(argc!=2)
	{
		printf("usage: ./msgque_receive type \n");
		printf("Example: msgque_receive  \n");
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
	
	msgctl(id,IPC_RMID,&buff);
	printf("Removing message Queue after receiving Data.....\n");
	return 0;
}
