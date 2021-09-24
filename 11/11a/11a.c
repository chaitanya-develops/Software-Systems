#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
  char str[100];
  printf("Enter the file name : ");
  scanf("%[^\n]s",str);
  int openfd;// original file's file descriptor
  openfd = open(str,O_CREAT|O_RDWR|O_TRUNC,0644);
  if (openfd == -1){
    printf("opening the file %s failed.\n",str);
    return -1;
  }
  int dupfd = dup(openfd);// duplicating the original file descriptor.
  // writing using original file descriptor.
  int wofd = write(openfd,"write() using original file descriptor\n",40);
  perror("fd write");
  // writing using duplicate file descriptor.
  int wdfd = write(dupfd,"write() using duplicate file descriptor\n",40);
  perror("dup-fd write");
  printf("original fd is %d, duplicate fd is %d\n",openfd,dupfd);
  close(openfd);
  close(dupfd);
}
