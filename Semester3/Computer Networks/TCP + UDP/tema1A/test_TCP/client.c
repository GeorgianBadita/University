#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int get_int(char *s){
  int i = 0, nr = 0;
  while(s[i]){
    nr = nr * 10 + (s[i++] - '0');
  }
  return nr;
}

int main(int argc, char **args) {
  int c;
  int n, i, dim;
  char a;

  struct sockaddr_in server;
  //uint16_t a, b, suma;

  c = socket(AF_INET, SOCK_STREAM, 0);
  if (c < 0) {
    printf("Eroare la crearea socketului client\n");
    return 1;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in localaddr;
  localaddr.sin_family = AF_INET;
  localaddr.sin_addr.s_addr = inet_addr(args[2]);
  localaddr.sin_port = 0;  // Any local port will do
  bind(sockfd, (struct sockaddr *)&localaddr, sizeof(localaddr));

  memset(&server, 0, sizeof(server));
  server.sin_port = htons(get_int(args[1]));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");


  if (connect(sockfd , (struct sockaddr *) &server, sizeof(server)) < 0) {
    printf("Eroare la conectarea la server\n");
    return 1;
  }
  recv(c, &n, sizeof(n), MSG_WAITALL);
  n = ntohl(n);
  recv(c, &dim, sizeof(dim), MSG_WAITALL);
  dim = ntohl(dim);
  printf("Numarul de conectari maxime: %d ", n);
  for(i = 0; i<dim; i++){
    recv(c, &a, sizeof(a), MSG_WAITALL);
    printf("%c", a);
  }
  printf("\n");

  close(c);
}
