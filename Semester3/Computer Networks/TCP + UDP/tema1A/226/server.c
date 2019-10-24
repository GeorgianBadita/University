#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int MAXIM = -1;

int main() {
  int s;
  struct sockaddr_in server, client;
  int c, l;
  
  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0) {
    printf("Eroare la crearea socketului server\n");
    return 1;
  }
  
  memset(&server, 0, sizeof(server));
  server.sin_port = htons(1234);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  
  if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
    printf("Eroare la bind\n");
    return 1;
  }
 
  listen(s, 5);
  
  l = sizeof(client);
  memset(&client, 0, sizeof(client));
  
  while (1) {
    c = accept(s, (struct sockaddr *) &client, &l);
    printf("S-a conectat un client.\n");
    // deservirea clientului
	int this_max = MAXIM;
	if(fork() == 0){
	printf("Here\n");
   	if(this_max == -1){
		printf("Maximul anterior: %d\n", MAXIM);
	}
	int num;
	recv(c, &num, sizeof(num), MSG_WAITALL);
	for(int i = 0; i<ntohl(num); i++){
		int num_r;
		recv(c, &num_r, sizeof(num_r), 0);
		num_r = ntohl(num_r);
		if(num_r > MAXIM){
			MAXIM = num_r;
		}
	}
		this_max = MAXIM;
		exit(0);
	}
    // sfarsitul deservirii clientului;
  }
}
