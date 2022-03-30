#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

#define KEY 8979

int main()
{
	int qid;
	struct msqid_ds buff;
	qid=msgget(32,IPC_CREAT|0644);
	printf("msgqid = %d\n",qid);
	msgctl(qid,IPC_STAT,&buff);
	printf("Details of message Queue \n");
	printf("number of msg's in Queue : %hi \n",buff.msg_qnum);
	//printf("number of bytes in Queue : %d \n",buff.msg_cbytes);
	printf("Max no. of bytes in Queue : %hi \n",buff.msg_qbytes);
	
	//get_queue_ds(qid, &buff);
	/*scanf(qid, "%ho", &buff.msg_perm.mode);
	msgctl(qid,IPC_SET,&buff);
	printf("Details of message Queue \n");
	printf("number of msg's in Queue : %hi \n",buff.msg_qnum);
	printf("Max no. of bytes in Queue : %hi \n",buff.msg_qbytes);
	printf("Mode change in Queue : %hi \n",buff.msg_perm.mode);*/
	
	return 0;
}
