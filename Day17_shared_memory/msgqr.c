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
	//char data1[1024];
};

int main(int argc,char **argv)
{
	struct my_msg_queue mq;
	struct my_msg_queue mq1;
	int id;
	
	if(argc!=2)
	{
		printf("usage: ./msgque_receive type \n");
		printf("Example: msgque_receive \n");
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
	
	msgrcv(id,&mq1,sizeof(mq1),atoi(argv[1]),0);
	printf("Data1 : %s\n",mq1.data);
	return 0;
}
