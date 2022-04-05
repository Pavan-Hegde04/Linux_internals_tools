#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char *ptr;
	int shmid;
	
	printf("...Creating Shared memory region...\n");
	shmid=shmget(50,100,IPC_CREAT|0644);		//created shared memory region
	perror("status of shared memory (created or not) : ");
	
	printf("\nshared memory id = %d ",shmid);	//printing shared memory id
	
	ptr=shmat(shmid,0,0);	//attaching shared memory
	printf("\nAddress at which shared memory region in the process is started is :: %p \n",ptr);
	return 0;
}
