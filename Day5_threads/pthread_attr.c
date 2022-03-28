#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
void * proc(void * param)
{
	sleep(2);
	return 0;
}
int main()
{
	pthread_attr_t Attr,Attr1;
	pthread_t Id;
	void *stk;
	size_t siz;
	int err;
	size_t my_stksize=300;
	void *my_stack;
	pthread_attr_init(&Attr);
	pthread_attr_init(&Attr1);
	pthread_attr_getstacksize(&Attr,&siz);
	pthread_attr_getstackaddr(&Attr,&stk);
	printf("Default:Addr =%08x  default size=%d\n",stk ,siz);
	my_stack=(void*)malloc(my_stksize);
	pthread_attr_setstack(&Attr1,my_stack,my_stksize);
	pthread_create(&Id,&Attr1,proc,NULL);
	pthread_attr_getstack(&Attr1,&stk,&siz);
	printf("newly defined stack : Addr %08x and size %d\n",my_stack,my_stksize);
	sleep(3);
	return 0;
}
