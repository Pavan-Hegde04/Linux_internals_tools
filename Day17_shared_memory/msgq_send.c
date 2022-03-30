#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
struct msgbuf
{
        long mtype;
        char data[100];
};
int main(int argc, char *argv[])
{
        struct msgbuf v1,v2;
        int id;
	int i;
	
        id=msgget(55,IPC_CREAT|0664);
	v1.mtype=10;
	for(i=0;i<100;i++)
	{
		v1.data[i]='a';
		
	}
	v2.mtype=20;
	for(i=0;i<100;i++)
		v2.data[i]='b';

       i= msgsnd(id,&v1,sizeof(v1),0);
       printf("return value of msgsnd of as = %d\n",i);
       i= msgsnd(id,&v2,sizeof(v2),0);
       printf("return value of msgsnd of bs = %d\n",i);

        return 0;
}

