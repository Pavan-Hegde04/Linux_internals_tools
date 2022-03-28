#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
        int pid;
        printf("current process pid = %d\n",getpid());
        pid=vfork();
        if(pid==0)
        {
                printf("child process pid = %d\n",getpid());
               
        }
        else
        {
                printf("parent process pid = %d\n",getpid());
               
        }
        exit(0);
                return 0;
}

