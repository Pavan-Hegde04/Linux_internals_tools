#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
struct my_thread
{
	int thread_id;
	char msg[50];
};
void *printmsg(void *threadobj)
{
	pthread_t thread_ID;
	struct my_thread *t1;
	t1=(struct my_thread*) threadobj;
	thread_ID = pthread_self();
	printf("\n thread ID : %u",thread_ID);
	printf("\nThis is Thread no.-%d & Showing Thread message : %s \n",t1->thread_id,t1->msg);
}
int main()
{
	pthread_t thread2,thread3,thread4,thread_ID;
	//int rc;
	struct my_thread t2,t3,t4;
	t4.thread_id=4;
	strcpy(t4.msg,"....Fourth thread....\n");
	t2.thread_id=2;
        strcpy(t2.msg,".....Second thread....\n");
	t3.thread_id=3;
        strcpy(t3.msg,"....Third thread....\n");
	thread_ID=pthread_self();
	printf("\n Main thread (First Thread) ID : %u\n",thread_ID);
	pthread_create(&thread4,NULL,printmsg,(void *)&t4);
	pthread_create(&thread2,NULL,printmsg,(void *)&t2);
	pthread_create(&thread3,NULL,printmsg,(void *)&t3);
	//printf("\n EXIT THREAD\n");
	printf("\n");
	pthread_exit(NULL);
}

