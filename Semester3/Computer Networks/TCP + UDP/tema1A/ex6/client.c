#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

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
  
  printf("Dati un caracter: ");
  char ch;
  scanf("%c", &ch);
 
  
  printf("Dati sirul de caractere: ");
  char str[10000];
  scanf("%s", str);
  int n = strlen(str);
  int new_n = htonl(n);


  send(c, &new_n, sizeof(new_n), 0);
  for(int i = 0; i<n; i++){
	  send(c, &str[i], sizeof(str[i]), 0);
  }
 
  send(c, &ch, sizeof(ch), 0);
  /*printf("Dati un caracter: ");
  char ch;
  scanf("%c", &ch);
  send(c, &ch, sizeof(ch), 0);*/

  recv(c, &n, sizeof(n), MSG_WAITALL);
  n = ntohl(n);
  printf("Numarul de potriviri: %d\n", n);
  for(int i = 0; i<n; i++){
	  int num;
	  recv(c, &num, sizeof(num), MSG_WAITALL);
	  num = ntohl(num);
	  printf("%d\n", num);
  }
  close(c);
}
