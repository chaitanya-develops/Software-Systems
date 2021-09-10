#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
// int symlink(const char *target, const char *linkpath);
int main(){
  int n;
  n = symlink("originalFile.txt","firstSoftLink.txt");
  printf("%d",n);
}
