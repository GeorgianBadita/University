#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
    int a2b[2], b2a[2];
    char s[] = "I'mastring\0";
    pipe(a2b);
    pipe(b2a);

    if(fork() == 0){
        close(a2b[0]);
        close(b2a[1]);
        printf("A: %s\n", s);
        while(1){
            s[strlen(s) - 1] = '\0';
            int k = strlen(s) + 1;
            write(a2b[1], &k, sizeof(int));
            write(a2b[1], s, k);
            int num;
            int val = read(b2a[0], &num, sizeof(int));
            if(val <= 0 || strlen(s) == 0){
                break;
            }    
            read(b2a[0], s, num);
            printf("A: %s\n", s);
        }

        close(a2b[1]);
        close(b2a[0]);
        exit(0);
    }
    if(fork() == 0){
        close(a2b[1]);
        close(b2a[0]);

        while(1){
            int num;
            int val = read(a2b[0], &num, sizeof(int));
            if(val <= 0){
                break;
            }
            read(a2b[0], s, num);
            if(strlen(s) == 0){
                break;
            }
            printf("B: %s\n", s);
            s[strlen(s) - 1] = '\0';
            num = strlen(s) + 1;
            write(b2a[1], &num, sizeof(int));
            write(b2a[1], s, num);
        }
        close(a2b[0]);
        close(b2a[1]);
        exit(0);
    }

    close(b2a[0]);
    close(b2a[1]);
    close(a2b[0]);
    close(a2b[1]);
    wait(0);
    wait(0);
    return 0;
}
                                                                                                                                   
