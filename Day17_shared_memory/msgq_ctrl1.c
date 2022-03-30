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

int main(int argc,char *argv[])
{
	struct my_msg_queue mq;
	struct msqid_ds buff;
	int id;
	
	id=msgget(100,IPC_CREAT|0644);
	
	
	mq.my_type=atoi(argv[1]); //ascii to int
	strcpy(mq.data,argv[2]);
	
	msgsnd(id,&mq,strlen(mq.data)+1,0);
	
	printf("msgqid = %d\n",id);
	msgctl(id,IPC_STAT,&buff);
	printf("Details of message Queue \n");
	printf("number of msg's in Queue : %hi \n",buff.msg_qnum);
	//printf("number of bytes in Queue : %d \n",buff.msg_cbytes);
	printf("Max no. of bytes in Queue : %hi \n",buff.msg_qbytes);
	return 0;
}
