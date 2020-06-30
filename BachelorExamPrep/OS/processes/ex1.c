#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
  int n = 1;
  if(fork() == 0){
    n = n + 1;
    exit(0);
  }
  n = n + 2;
  printf("%d: %d\n", getpid(), n);
  wait(0);
  return 0;
}
