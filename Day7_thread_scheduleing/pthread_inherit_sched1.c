#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<sys/mman.h>

void *proc(void *param)
{
	sleep(3);
	return 0;
}
int main(int argc, char *argv[])
{
	pthread_attr_t Attr;
	pthread_t Id;
	int err,info;
	pthread_attr_init(&Attr);
	pthread_attr_getinheritsched(&Attr,&info);
	switch(info)
	{
		case PTHREAD_INHERIT_SCHED:
			printf("\n SCHED\n");
			break;
		case PTHREAD_EXPLICIT_SCHED:
			printf("\n EXPLICIT\n");
			break;
	}
	pthread_attr_setinheritsched(&Attr,PTHREAD_EXPLICIT_SCHED);
	pthread_attr_getinheritsched(&Attr,&info);
	switch(info)
	{
		case PTHREAD_INHERIT_SCHED:
			printf("\n SCHED\n");
			break;
		case PTHREAD_EXPLICIT_SCHED:
			printf("\n EXPLICIT\n");
			break;
	}
	printf("\nprocess creating thread once whose sched policy is given by thread task proc\n");
	pthread_create(&Id,&Attr,proc,NULL);
	pthread_join(Id,NULL);
	return 0;
}
