#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
int fd;
char *temp,*temp1,*temp2;
temp="hello";  //filename
temp1="Funny"; 
temp2="world";
execl("hello",temp,temp1,temp2,NULL);
printf("Error");
return 0;
} 
