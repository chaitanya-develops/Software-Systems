#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
  char str[100];
  printf("Enter the filename : ");
  scanf("%[^\n]s",str);
  // opening the specified file, creates one if doesnot exist.
  int openfd = open(str,O_CREAT|O_RDWR|O_TRUNC,0644);
  perror("open ");
  // using fcntl to get file status flags.
  int flags = fcntl(openfd,F_GETFL);
  perror("fcntl ");
  printf("The %s file's status flags are %d\n",str,flags);
  // last two bits of the binary representation of flags indicates access mode.
  printf("file descriptor : %d\n", openfd);
  // O_ACCMODE = 11 in binary.
  // O_RDONLY = 00 in binary.
  // O_WRONLY = 01 in binary.
  // O_RDWR = 10 in binary.
  printf("access mode masked with flags : %d\n",flags&O_ACCMODE);
  if ((flags & O_ACCMODE) == O_RDONLY){
      printf("opening mode of the file is O_RDONLY\n");
  }
  if ((flags & O_ACCMODE) == O_WRONLY){
      printf("opening mode of the file is O_WRONLY\n");
  }
  if ((flags & O_ACCMODE) == O_RDWR){
      printf("opening mode of the file is O_RDWR\n");
  }
  return 1;
}
