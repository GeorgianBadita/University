#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
  int i;
  for(i = 0; i<2; i++){
    printf("%d: %d\n", getpid(), i);
    if(fork() == 0){
      printf("%d: %d\n", getpid(), i);
      exit(0);
    }
  }
  for(i = 0; i<2; i++){
    wait(0);
  }
  return 0;
}
