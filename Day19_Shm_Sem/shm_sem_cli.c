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
#define MSG_LEN 256
#define RESP_MSG_START 256


int main()
{
	int sem_id,shm_id;
	char *ptr_shm;
	struct sembuf smop;
	
	sem_id = semget(KEY,1,0660);  //create a semaphore set, containing two semaphores
	
	if(sem_id<0)
	{
		printf("Semaphore is not created \n");
		return 1;
	}
	else
	{
		printf("Semaphore ID is : %d \n",sem_id);
	}
	
	
	shm_id=shmget(KEY,SIZE,0660);  //create a shared memory segment
	
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
		printf("Client : Enter some request message that you have to send to server \n");
		fgets(ptr_shm,MSG_LEN,stdin);
		
		//wait for token for semaphore 0
		smop.sem_num=0;
		smop.sem_op=1;
		smop.sem_flg=0;
		
		semop(sem_id,&smop,1);
		
		//send token to semaphore 1
		smop.sem_num=1;
		smop.sem_op=-1;
		smop.sem_flg=0;
		
		semop(sem_id,&smop,1);
		
		puts(ptr_shm+RESP_MSG_START);
	}
	return 0;
}

