#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main()
{
	char *p;
	int id;
	
	id=shmget(48,250,IPC_CREAT|0644);//Kernel Space
	
	if(id<0)
	{
		perror("shmget");
		return 0;
	}
	
	printf("shmid = %d \n",id);
	p=shmat(id,0,SHM_RDONLY);//PAS----User space
	printf("Data :  %s \n",p);
	shmdt(p);
	return 0;
}
