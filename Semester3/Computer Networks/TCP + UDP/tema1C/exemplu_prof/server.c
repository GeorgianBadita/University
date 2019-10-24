#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>

int main() {
  int s;
  struct sockaddr_in server, client;
  int c, l, i;
  uint16_t k, old = 0;
  
  s = socket(AF_INET, SOCK_DGRAM, 0);
  if (s < 0) {
    printf("Eroare la crearea socketului server\n");
    return 1;
  }
  
  memset(&server, 0, sizeof(server));
  server.sin_port = htons(1345);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  
  if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
    printf("Eroare la bind\n");
    return 1;
  }
 
  l = sizeof(client);
  memset(&client, 0, sizeof(client));
 
 while(1){ 
  sleep(0.5);
  unsigned int number = 0;
  old = 0;
  for (i = 0; i < 2; i++) {
    recvfrom(s, &k, sizeof(k), MSG_WAITALL, (struct sockaddr *) &client, &l);
    k = ntohs(k);
//    printf("Am primit: %hu la pasul %d\n", k, i+1);
    if (k != old + 1){
      number ++;
	}
    old = k;
  }
	printf("Gresite din 2: %f\n", (double)((2-number*1.0)/(2)));
 }
  close(s);
}
