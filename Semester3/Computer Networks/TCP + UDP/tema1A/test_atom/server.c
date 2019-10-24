#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
#define MIN(A, B) (A<=B ? A : B)

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
    int len1, len2;
    char *s1, *s2;
    recv(c, &len1, sizeof(len1), MSG_WAITALL);
    len1 = ntohl(len1);
    recv(c, &len2, sizeof(len2), MSG_WAITALL);
    len2 = ntohl(len2);
    s1 = (char*)malloc(len1*sizeof(char));
    s2 = (char*)malloc(len2*sizeof(char));
    for(int i = 0; i<len1; i++){
      char a;
      recv(c, &a, sizeof(a), MSG_WAITALL);
      s1[i] = a;
    }
    for(int i = 0; i<len2; i++){
      char a;
      recv(c, &a, sizeof(a), MSG_WAITALL);
      s2[i] = a;
    }

    int table[26];
    for(int i = 0; i<26; i++){
      table[i] = 0;
    }
    for(int i = 0; i<MIN(len1, len2); i++){
      if(s1[i] == s2[i]){
        table[s1[i] - 'a'] ++;
      }
    }
    int maxim = -1, pos = 0;
    for(int i = 0; i<26; i++){
      if(table[i] > maxim){
        maxim = table[i];
        pos = i;
      }
    }
    char ret = 'a' + pos;
    send(c, &ret, sizeof(ret), 0);
    free(s1);
    free(s2);
    close(c);
    // sfarsitul deservirii clientului;
  }
}
