#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
int main() {
	
  int c;
  struct sockaddr_in server;
  
  c = socket(AF_INET, SOCK_STREAM, 0);
  if (c < 0) {
    printf("Eroare la crearea socketului client\n");
    return 1;
  }
  
  memset(&server, 0, sizeof(server));
  server.sin_port = htons(1234);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  
  if (connect(c, (struct sockaddr *) &server, sizeof(server)) < 0) {
    printf("Eroare la conectarea la server\n");
    return 1;
  } 

  int to_send, n, *v;
  printf("Dati numarul de elemente: ");
  scanf("%d", &n);

  v = (int*)malloc(n*sizeof(int));

  for(int i = 0; i<n; i++){
	  printf("Dati numarul %d: ", i);
	  scanf("%d", &v[i]);
  }

  to_send = htonl(n);
  send(c, &to_send, sizeof(to_send), 0);
  for(int i = 0; i<n; i++){
	  to_send = htonl(v[i]);
	  send(c, &to_send, sizeof(to_send), 0);
  }
  free(v);
  close(c);
}
