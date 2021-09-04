#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
  int n;
  char buff[100];
  int fd;
  fd = open("tester.txt", O_RDWR);
  n = read(fd,buff,100);
  write(1,buff,100);
}
