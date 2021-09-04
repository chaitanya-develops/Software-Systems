#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  int fd = creat("FirstFile.txt",0766);
  printf("%d\n", fd);
}
