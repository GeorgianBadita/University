#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
  printf("ParentPID: %d\n", getpid());
  for(int i = 0; i<4; i++){
    fork();
  }
  //int n = 100;
  while(wait(NULL) > 0)
  {
    //n --;
    //printf("RET: %d\n", wait(NULL));
  }
  printf("Whatever: %d\n", getpid());
  return 0;
}
