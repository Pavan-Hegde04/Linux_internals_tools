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

int main(int argc,char *argv[])
{
	struct my_msg_queue mq;
	int id;
	
	id=msgget(100,IPC_CREAT|0644);
	
	printf("id = %d\n",id);
	mq.my_type=atoi(argv[1]); //ascii to int
	strcpy(mq.data,argv[2]);
	
	msgsnd(id,&mq,strlen(mq.data)+1,0);
	return 0;
}
