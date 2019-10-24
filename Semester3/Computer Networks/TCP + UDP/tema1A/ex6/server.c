#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
 
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
    uint16_t a, b, suma;
    c = accept(s, (struct sockaddr *) &client, &l);
    printf("S-a conectat un client.\n");
    // deservirea clientului
 	int dim;
   	recv(c, &dim, sizeof(dim), MSG_WAITALL);
	dim = ntohl(dim);
	int pos[dim + 1], index = 0;
	char str[dim + 1];
	str[dim] = '\0';
	for(int i = 0; i<dim; i++){
		char a;
		recv(c, &a, sizeof(a), MSG_WAITALL);
		str[i] = a;
	}
	
	char ch;
	recv(c, &ch, sizeof(ch), MSG_WAITALL);

	for(int i = 0; i<dim; i++){
		if(str[i] == ch){
			pos[index] = i;
			index ++;
		}
	}
	int to_send = htonl(index);
	send(c, &to_send, sizeof(to_send), 0);
	for(int i = 0; i<index; i++){
		int num = htonl(pos[i]);
		send(c, &num, sizeof(num), 0);
	}
    close(c);
    // sfarsitul deservirii clientului;
  }
}
