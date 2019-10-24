#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
  int s, ss, l;
  struct sockaddr_in server, server2, client;	//socketul pentru prima conecxiune, a 2-a si clinet

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
  }		//bind pe prima conexiune

  ss = socket(AF_INET, SOCK_STREAM, 0);
  if(ss < 0){
	  printf("Eroare la crearea noului socket server\n");
	  return 1;
  }

  memset(&server2, 0, sizeof(server2));		//initializare socket server 2
  server2.sin_port = htons(2003);		//cu portul triis
  server2.sin_family = AF_INET;
  server2.sin_addr.s_addr = INADDR_ANY;

  if(bind(ss, (struct sockaddr *) &server2, sizeof(server2)) < 0){
	  printf("Eroare la bind 2\n");
	  return 1;		//bind pe al 2-lea socket
  }

  listen(s, 5);	//listen pe scketul 1
  listen(ss, 5);//listen pe socketul 2

  l = sizeof(client);
  memset(&client, 0, sizeof(client));	//curatare client

  while (1) {
    int cc, c;
    c = accept(s, (struct sockaddr *) &client, &l);
    printf("S-a conectat un client.\n");
    // deservirea clientului
	short int port = 2003;
	port = htons(port);
	send(c, &port, sizeof(port), 0);
	//trimterea noului port


	memset(&client, 0, sizeof(client));
	l = sizeof(client);
	cc = accept(ss, (struct sockaddr*) &client, &l); //conectarea la clinet prin noul port

	printf("Te-ai conectat din nou :)!\n");
	int num_char;
	recv(cc, &num_char, sizeof(num_char), MSG_WAITALL);
	printf("Numarul de barosi este: %d\n", ntohl(num_char));
	num_char = ntohl(num_char);		//primi numarul de caractere de la client prin portul nou

	char* str = (char*)malloc(num_char*sizeof(char));
	for(int i = 0; i<num_char; i++){
		char a;
		recv(cc, &a, sizeof(a), MSG_WAITALL);	//citim sirul de caractere
		str[i] = a;
	}

	for(int i = 0; i<num_char; i++){
		str[i] = 'B';		//cream un nou sir
	}

	int to_send = htonl(num_char);	//trimitem inapoi lungimea
	send(cc, &to_send, sizeof(to_send), 0);
	for(int i = 0; i<num_char; i++){
		send(cc, &str[i], sizeof(str[i]), 0);	//trimitem inapoi sirul
	}
    close(c);
    close(cc);
    // sfarsitul deservirii clientului;
  }
}
