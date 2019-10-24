#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>

void sorteaza(int *v, int n){
	int ok = 0;
	do{
		ok = 1;
		for(int i = 0; i<n - 1; i++){
			if(v[i] > v[i + 1]){
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				ok = 0;
			}
		}
	}while(ok == 0);
}

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
  
  int n, m;
  int *v, *w;
  printf("Dati numarul de elemente pentru sirul 1: ");
  scanf("%d", &n);
  v = (int*)malloc(n*sizeof(int));
  for(int i = 0; i<n; i++){
	  printf("Dati elementul %d: ", i);
	  scanf("%d", &v[i]);
  }

  sorteaza(v, n);

  printf("Dati numarul de elemente pentru sirul 2: ");
  scanf("%d", &m);
  w = (int*)malloc(m*sizeof(int));
  for(int i = 0; i<m; i++){
	  printf("Dati elementul %d: ", i);
	  scanf("%d", &w[i]);
  }
  sorteaza(w, n);
  
  int n_copy = htonl(n), m_copy = htonl(m);
  send(c, &n_copy, sizeof(n_copy), 0);
  for(int i = 0; i<n; i++){
	  int to_send = htonl(v[i]);
	  send(c, &to_send, sizeof(to_send), 0);
  }
  send(c, &m_copy, sizeof(m_copy), 0);
  for(int i = 0; i<m; i++){
	  int to_send = htonl(w[i]);
	  send(c, &to_send, sizeof(to_send), 0);
  }
  int total;
  recv(c, &total, sizeof(total), MSG_WAITALL);
  total = ntohl(total);
  for(int i = 0; i<total; i++){
	  int num;
	  recv(c, &num, sizeof(num), MSG_WAITALL);
	  num = ntohl(num);
	  printf("%d ", num);
  }
  printf("\n");
  free(v);
  free(w);
  close(c);
}
