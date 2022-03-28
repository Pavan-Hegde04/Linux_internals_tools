#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int arr[2];//arr[0],arr[1] indexes or subscripts of array 
	
	pipe(arr);//fd(0)--arr(0)rd end  and fd(1)--arr(1)wr end
	printf("Read end of pipe = %d \t Write end of pipe = %d\n",arr[0],arr[1]);// 3, 4,.....0 1 2 OS(predefined)
	if(fork())
	{
		//parent
		
		char buff[20];
		printf("In parent enter data....\n");
		scanf("%s",buff);
		write(arr[1],buff,strlen(buff)+1);
	}
	else
	{
		//child
		
		char buff1[20];
		printf("In child.....\n");
		read(arr[0],buff1,sizeof(buff1));
		printf("child pro printing... data. of the parent process...%s\n",buff1);
	}
	return 0;
}
