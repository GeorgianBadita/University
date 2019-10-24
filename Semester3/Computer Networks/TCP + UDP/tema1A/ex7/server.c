#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
int get_int(char* s){
	int i = 0, nr = 0;
	while(s[i]){
		nr = nr * 10 + (s[i++] - '0');
	}
	return nr;
}

int main(int argc, char** args) {
  int s;
  struct sockaddr_in server, client;
  int c, l;
  
  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0) {
    printf("Eroare la crearea socketului server\n");
    return 1;
  }
  
  memset(&server, 0, sizeof(server));
  server.sin_port = htons(get_int(args[1]));
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
   	int nr;
	recv(c, &nr, sizeof(nr), MSG_WAITALL);
	nr = ntohl(nr);
	char *str = (char*)malloc(nr*sizeof(char));

	for(int i = 0; i<nr; i++){
		char a;
		recv(c, &a, sizeof(a), MSG_WAITALL);
		str[i] = a;
	}
	int i, l;
	recv(c, &i, sizeof(i), 0);
	i = ntohl(i);
	recv(c, &l, sizeof(l), 0);
	l = ntohl(l);
	for(int j = i; j<i+l; j++){
		char a = str[j];
		send(c, &a, sizeof(a), 0);
	}
	free(str);
    close(c);
    // sfarsitul deservirii clientului;
  }
}
