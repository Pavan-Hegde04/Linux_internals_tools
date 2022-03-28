#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *start_one(void *arg)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("thread of con 1\n");
	}
}

void *start_two(void *arg)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("** thread of con 2\n");
	}
}

int main()
{
	pthread_t pt1,pt2;
	getchar();
	pthread_create(&pt1,NULL,start_one,NULL);
	pthread_create(&pt2,NULL,start_two,NULL);
	getchar();
	printf("end of main thread\n");
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	return 0;
}
