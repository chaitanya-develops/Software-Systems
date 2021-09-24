#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
  char str[100];
  char buf1[100] = "write() using the original file descriptor \n";
  char buf2[100] = "write() using the duplicated file descriptor \n";
  printf("Enter the file name : ");
  scanf("%[^\n]s",str);
  int openfd = open(str,O_CREAT|O_RDWR|O_TRUNC,0644);
  perror("open ");
  // dup2 uses the newfd given to duplicate the original file descriptor.
  // dup2 closes the newfd if it is open and original fd is valid.
  // if newfd is same as oldfd , nothing is done , new fd is returned.
  int dup2fd = dup2(openfd,45);
  perror("dup2 ");
  int wofd = write(openfd,buf1,100);
  perror("write fd ");
  int wd2fd = write(dup2fd,buf2,100);
  perror("write dup2-fd ");
  printf("original file descriptor : %d\nduplicate file descriptor :  %d\n",openfd,dup2fd);
  close(openfd);
  close(dup2fd);
}
