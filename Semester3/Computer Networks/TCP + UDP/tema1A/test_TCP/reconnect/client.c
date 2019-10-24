#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
  int c;
  struct sockaddr_in server; //server socket
  uint16_t a, b, suma;

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
  }	//conectarea clientului

  short int port;
  recv(c, &port, sizeof(port), MSG_WAITALL); //primirea noului port de la server
  printf("Portul: %hu\n", ntohs(port));



  int cc;
  struct sockaddr_in server1;
  cc = socket(AF_INET, SOCK_STREAM, 0); //crearea noului socket pentru noua conectiune
  if(cc < 0){
	  printf("Eroare la crearea noului socket\n");
	  return 1;
  }
  memset(&server1, 0, sizeof(server1));
  server1.sin_port = port;		//atribuirea cu portul citit
  server1.sin_family = AF_INET;
  server1.sin_addr.s_addr = inet_addr("127.0.0.1");
  if(connect(cc, (struct sockaddr *) &server1, sizeof(server1)) < 0){
	  printf("Eroare la noua conectare la server\n");
	  return 1;
  }			//conectarea prin noul socket la server

  printf("Dati numarul de caractere: ");
  int num_char;
  scanf("%d", &num_char);
  int to_send = htonl(num_char);
  send(cc, &to_send, sizeof(to_send), 0);		//trimitem inapoi lungimea sirului de caractere
  char *str = (char*)malloc(num_char*sizeof(char));

  scanf("%s", str);
  for(int i = 0; i<num_char; i++){
	  send(cc, &str[i], sizeof(str[i]), 0);	//trimitem pe rand fiecare caracter
  }

  recv(cc, &num_char, sizeof(num_char), MSG_WAITALL);		//primim numarul de caractere primite
  num_char = ntohl(num_char);

  for(int i = 0; i<num_char; i++){
	  recv(cc, &str[i], sizeof(str[i]), MSG_WAITALL);
  }
  printf("Sirul primit este: %s\n", str);	//afisarea sirului primit


  close(c);
  close(cc);
}
