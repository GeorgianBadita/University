#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
  int c;
  struct sockaddr_in server;
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
  }
  char s1[1000], s2[1000];

  printf("Dati primul sir: ");
  scanf("%s", s1);
  printf("Dati al 2-lea sir: ");
  scanf("%s", s2);
  int n, m, n_copy, m_copy;
  n = strlen(s1);
  m = strlen(s2);
  n_copy = htonl(n);
  m_copy = htonl(m);
  send(c, &n_copy, sizeof(n_copy), 0);
  send(c, &m_copy, sizeof(m_copy), 0);
  for(int i = 0; i<n; i++){
    send(c, &s1[i], sizeof(s1[i]), 0);
  }
  for(int i = 0; i<m; i++){
    send(c, &s2[i], sizeof(s2[i]), 0);
  }
  char rez;
  recv(c, &rez, sizeof(rez), MSG_WAITALL);
  printf("Caracterul este: %c\n", rez);
  close(c);
}
