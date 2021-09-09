#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
  int n[100];
  read(2,n,50);
  write(1,n,50);
}
