#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
  int n;
  n = mknod("firtNamedpipe",00777|S_IFIFO,0);
  printf("%d",n);
}
