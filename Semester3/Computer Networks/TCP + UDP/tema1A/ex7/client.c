#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int get_int(char* s){
	int i = 0, nr = 0;
	while(s[i]){
		nr = nr * 10 + (s[i++] - '0');
	}
	return nr;
}
 
int main(int argc, char** args) {
  int c;
  struct sockaddr_in server;
  uint16_t a, b, suma;
  
  c = socket(AF_INET, SOCK_STREAM, 0);
  if (c < 0) {
    printf("Eroare la crearea socketului client\n");
    return 1;
  }
  
  memset(&server, 0, sizeof(server));
  server.sin_port = htons(get_int(args[1]));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  
  if (connect(c, (struct sockaddr *) &server, sizeof(server)) < 0) {
    printf("Eroare la conectarea la server\n");
    return 1;
  }
 
  char str[1000];
  scanf("%s", str);
  int nr, n = strlen(str);
  nr = htonl(n);
  send(c, &nr, sizeof(nr), 0);
  
  for(int i = 0; i<n; i++){
	  send(c, &str[i], sizeof(str[i]), 0);
  }

  int i, l, len;
  scanf("%d%d", &i, &l);
  len = l;
  i = htonl(i);
  l = htonl(l);
  send(c, &i, sizeof(i), 0);
  send(c, &l, sizeof(l), 0);

  for(int i = 0; i<len; i++){
  	char a;
	recv(c, &a, sizeof(a), MSG_WAITALL);
	printf("%c ", a);
  }
  printf("\n");
  close(c);
}

