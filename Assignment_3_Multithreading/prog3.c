#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

void *proc(void *param)
{
	sleep(2);
	return 0;
}

int main()
{
	pthread_attr_t Attr;
	pthread_attr_t Attr1;
	pthread_t id1;
	pthread_t id2;
	void *stk;
	size_t siz;
	int err;
	size_t my_stksize=300;
	void *my_stack;
	pthread_attr_init(&Attr);
	pthread_attr_init(&Attr1);
	pthread_create(&id2,&Attr1,proc,NULL);
	
	pthread_attr_getstack(&Attr1,&stk,&siz);
	
	printf("Default: Addr=%08x Default size=%d\n",stk,siz);
	my_stack=(void *)malloc(my_stksize);

	printf("Malloc check: Addr=%08x Default size=%d\n",my_stack,my_stksize);
	
	pthread_attr_setstack(&Attr,my_stack,my_stksize);

	pthread_create(&id1,&Attr,proc,NULL);
	pthread_attr_getstack(&Attr,&stk,&siz);
	printf("newly defined stack : Addr=%08x and Size=%d\n",my_stack,my_stksize);
	sleep(3);
	return 0;
}
