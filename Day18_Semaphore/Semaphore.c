#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<string.h>
#include<semaphore.h>
#include<unistd.h>

union semaphore_num
{
	int val;
	struct sid_ds *buf;
	unsigned short *array;
	struct seminfo *_buf;
};

int get_release(void);
int get_semaphore(void);
struct sembuf sem_op;
union semaphore_num sem_union;
int semid;

int main()
{
	int i;
	sleep(2);
	
	semid=semget((key_t)10,1,0666|IPC_CREAT);
	printf("\n Semaphore Id : %d\n",semid);
	
	sem_union.val=1;
	
	if(semctl(semid,0,SETVAL,sem_union)<0)
	{
		printf("ERROR \n");
	}
	
	for(i=0;i<=5;i++)
	{
		get_semaphore();
		printf("\n %d : Got the semaphore \n",getpid());
		sleep(1);
		printf("\n %d : Release the semaphore \n",getpid());
		get_release();
		sleep(1);
	}
	
	if(semctl(semid,0,IPC_RMID,sem_union)<0)
	{
		printf("Fails to delete the semaphore \n");
	}	
	else
	{
		printf("\n Semaphore Deleted \n");
	}
	
	
	return 0;
}

int get_semaphore(void)
{
	sem_op.sem_num=0;
	sem_op.sem_op=-1;
	sem_op.sem_flg=SEM_UNDO;
	if(semop(semid,&sem_op,1)<0)
	{
		printf("Failed \n");
		return -1;
	}
	
}

int get_release(void)
{
	sem_op.sem_num=0;
	sem_op.sem_op=1;
	sem_op.sem_flg=SEM_UNDO;
	if(semop(semid,&sem_op,1)<0)
	{
		printf("Failed \n");
		return -1;
	}
}
