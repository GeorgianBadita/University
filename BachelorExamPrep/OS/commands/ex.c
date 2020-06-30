#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define N 6
#define K 4
int main() {
 int i, n=1, p[N][2];
 for(i=0; i<N; i++) { pipe(p[i]); }
 write(p[0][1], &n, sizeof(int));
 for(i=0; i<K*N; i+=K) {
 if(fork() == 0) {
 read(p[i%N][0], &n, sizeof(int));
 n++;
 write(p[(i+K)%N][1], &n, sizeof(int));
 exit(0);
 }
 }
 for(i=0; i<N; i++) { wait(0); }
 read(p[0][0], &n, sizeof(int));
 printf("%d\n", n);
 return 0;
}
