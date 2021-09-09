#include<stdio.h>
#include<sys/types.h>
#include <sys/stat.h>
// #include < fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int errcheck = system("cp original.txt copied.txt");
    if (errcheck == -1){
      printf("Failed to copy a file");
    }
    else{
      printf("Succesfully copied");
    }
}
