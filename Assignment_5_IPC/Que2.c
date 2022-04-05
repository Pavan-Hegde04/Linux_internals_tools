#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

#define KEY 8008

struct my_msg_queue
{
	long my_type;
	char data[100];
};

int main()
{
	struct my_msg_queue obj1;
	int msgqid;
	int temp;
	struct msqid_ds msgqueue;
	
	msgqid=msgget(50,IPC_CREAT|0644);	//creating message Queue
	printf("... Creating Message Queue ...\n");	
	printf("Message Queue id = %d\n",msgqid);	//printing message Queue id
	
	obj1.my_type=20;
	obj1.data[100]="Pavan Hegde";
	temp=msgsnd(msgqid,&obj1,sizeof(obj1),IPC_NOWAIT);	//sending message to Message Queue with flag IPC_NOWAIT
	printf("return value of msgsnd = %d\n",temp);
	
	msgctl(msgqid,IPC_STAT,&msgqueue);	//using msgctl() printing stats
	printf("\nStatistics of message Queue Structure \n");
	printf("Number of message's in Queue : %li \n",msgqueue.msg_qnum);
	printf("Number of bytes in Queue : %ld \n",msgqueue.msg_cbytes);
	printf("Max no. of bytes in Queue : %li \n",msgqueue.msg_qbytes);
	
	msgctl(msgqid,IPC_RMID,&msgqueue);	//removing message Queue
	printf("\n... Removing Message Queue ...\n");
	return 0;
}
