#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
  char str[100];
  char buf1[100] = "write() using original file descriptor\n";
  char buf2[100] = "write() using duplicate file descriptor\n";
  printf("Enter the name of the file: ");
  scanf("%[^\n]s",str);
  // creating and opening the file.
  int openfd = open(str,O_CREAT|O_RDWR|O_TRUNC,0644);
  perror("open: ");
  // duplicating fd of the file using fcntl.
  // works same as dup() system call.
  // on success returns the minimum avaiable fd.
  int dupfd = fcntl(openfd,F_DUPFD);
  perror("fcntl: ");
  // writing using original file descriptor.
  int wofd = write(openfd,buf1,50);
  perror("write fd: ");
  // writing using duplicate file descriptor.
  int wdfd = write(dupfd,buf2,50);
  perror("write dup-fd: ");
  printf("original file descriptor is : %d\n",openfd);
  printf("duplicated file descriptor is : %d\n",dupfd);
  close(openfd);
  close(dupfd);
}
