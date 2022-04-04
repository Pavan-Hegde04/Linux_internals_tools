#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<string.h>
#include<semaphore.h>
#include<unistd.h>

#define KEY 199
#define SIZE 0x1000

void toogle(char *buf,int count);

union semun
{
	int val;  			//value for SETVAL
	struct semid_ds *buf;		//Buffer for IPC_STAT, IPC_SET
	unsigned short *array;		//ARray for GETALL,SETALL
	struct seminfo *__buf;		//Buffer for IPC_INFO (Linux specific)
};
union semun sem_union;  //used intarnally by kernel

int main()
{
	int sem_id,shm_id;
	char *ptr_shm;
	struct sembuf smop;
	
	sem_id = semget(KEY,1,0660|IPC_CREAT);  //create a semaphore set, containing two semaphores
	if(sem_id<0)
	{
		printf("Semaphore is not created \n");
		return 1;
	}
	else
	{
		printf("Semaphore ID is : %d \n",sem_id);
	}
	
	semctl(sem_id,0,SETVAL,0);  //set initial token count of both semaphore to zeros
	
	shm_id=shmget(KEY,SIZE,0660|IPC_CREAT);  //create a shared memory segment
	
	if(shm_id<0)
	{
		printf("Shared memory segment is not created \n");
		return 2;
	}
	
	ptr_shm=shmat(shm_id,NULL,0);  //attach shared memory segment to process address space
	if(!ptr_shm)
	{
		printf("Shared memory segment is not attached");
		return 3;
	}
	
	while(1)  //server initiated and waiting for client, untill client connected to server is called to be Blocking Mode
	{
		//wait for token for semaphore 0
		smop.sem_num=0;
		smop.sem_op=-1;
		smop.sem_flg=0;
		
		semop(sem_id,&smop,1);
		
		//this is critical section we are protecting
		//process the message available in shared memory
		printf("Semaphore got\n");
		strcpy(ptr_shm+256,ptr_shm);
		toggle(ptr_shm+256,strlen(ptr_shm+256));
		printf("Processed the request message and placed response\n");
		
		//send token to semaphore 1
		smop.sem_num=1;
		smop.sem_op=1;
		smop.sem_flg=0;
		
		semop(sem_id,&smop,1);
	}
	return 0;
}

void toggle(char *buf,int count)
{
	int x;
	for(x=0;x<count;x++)
	{
		if((buf[x]>='A')&&(buf[x]<='Z'))
		{
			buf[x]+=0x20;
		}
		else if((buf[x]>='a')&&(buf[x]<='z'))
		{
			buf[x]-=0x20;
		}
	}
}
