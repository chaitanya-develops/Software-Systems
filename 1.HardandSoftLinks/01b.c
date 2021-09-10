#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
  int n;
  n = link("originalFile.txt","firstHardLink.txt");
  printf("%d",n);
}
