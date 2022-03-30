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
int main(int argc, char**argv)
{
        int id;
	int i;

        struct msgbuf v1,v2;
        id=msgget(55,IPC_CREAT|0664);
        
        i=msgrcv(id,&v1,sizeof(v1),10,0);
        for(i=0;i<100;i++)
		printf("%c",v1.data[i]);
	printf("\n");
	i=msgrcv(id,&v2,sizeof(v2),20,0);
        for(i=0;i<100;i++)
                printf("%c",v2.data[i]);
        printf("\n");

        return 0;
}


