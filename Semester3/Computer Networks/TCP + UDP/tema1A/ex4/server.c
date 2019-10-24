#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>


void interclas(int *v, int n, int *w, int m, int *rez){
	int i, j, pos;
	i = 0, j = 0, pos = 0;
	while(i < n && j < m){
		if(v[i] <= w[j]){
			rez[pos] = v[i];
			i ++;
		}else {
			rez[pos] = w[j];
			j ++;
		}
		pos ++;
	}
	while(i < n){
		rez[pos++] = v[i];
		i ++;
	}

	while(j < m){
		rez[pos++] = w[j];
		j ++;
	}
}

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
	int n, m, *v, *w, *concat;
	recv(c, &n, sizeof(n), MSG_WAITALL);
	n = ntohl(n);
	v = (int*)malloc(n*sizeof(int));
	for(int i = 0; i<n; i++){
		int num;
		recv(c, &num, sizeof(num), MSG_WAITALL);
		num = ntohl(num);
		v[i] = num;
	}
	recv(c, &m, sizeof(m), MSG_WAITALL);
	m = ntohl(m);
	w = (int*)malloc(m*sizeof(int));
	for(int i = 0; i<m; i++){
		int num;
		recv(c, &num, sizeof(num), MSG_WAITALL);
		num = ntohl(num);
		w[i] = num;
	}
	
	concat = (int*)malloc((m+n)*sizeof(int));
	interclas(v, n, w, m, concat);
	
	int total = m + n;
	total = htonl(total);
	send(c, &total, sizeof(total), 0);
	for(int i = 0; i<m+n; i++){
		int to_send = concat[i];
		to_send = htonl(to_send);
		send(c, &to_send, sizeof(to_send), 0);
	}

	for(int i = 0; i<n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
	
	for(int i = 0; i<m; i++){
		printf("%d ", w[i]);
	}
	printf("\n");

	for(int i = 0; i<m+n; i++){
		printf("%d ", concat[i]);
	}
	printf("\n");
	free(v);
	free(w);
	free(concat);
    // deservirea clientului
    close(c);
    // sfarsitul deservirii clientului;
  }
}
