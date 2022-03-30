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

int main(int argc,char *argv[])
{
	struct my_msg_queue mq;
	struct my_msg_queue mq1;
	int id;
	
	id=msgget(100,IPC_CREAT|0644);
	
	printf("id = %d\n",id);
	mq.my_type=atoi(argv[1]); //ascii to int
	mq1.my_type=atoi(argv[1]);
	strcpy(mq.data,argv[2]);
	strcpy(mq1.data,argv[3]);
	msgsnd(id,&mq,strlen(mq.data)+1,0);
	msgsnd(id,&mq1,strlen(mq1.data)+1,0);
	return 0;
}
