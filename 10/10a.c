#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
  int openfd;// holds the file descriptor of file writing into.
  int buffer[20];// buffer to read into and write from.
  int len;// holds number of characters read.
  int offset;// holds the offset value returned by lseek system call.
  openfd = open("10.txt",O_CREAT|O_RDWR|O_TRUNC,0644);
  len = read(1,buffer,10);// reading 10 characters from stdin.
  write(openfd,buffer,len);// writing 10 charcters into the file.
  offset = lseek(openfd,len,SEEK_CUR);// moving the offset value by 10.
  perror("lseek");
  len = read(1,buffer,10);// reading 10 more characters from stdin.
  write(openfd,buffer,len);// writing 10 characters into file.
//output:
// $od -c 10.txt
// 0000000   "   f   i   r   s   t   o   n   e   "  \0  \0  \0  \0  \0  \0
// 0000020  \0  \0  \0  \0   s   e   c   o   n   d   o   n   e   "
// 0000036

// whence takes:
//   SEEK_SET : starts offsetting from start of the file.
//   SEEK_CUR : starts offsetting from current offset of file.
//   SEEK_END : offset is set to file size plus offset bytes.

}
