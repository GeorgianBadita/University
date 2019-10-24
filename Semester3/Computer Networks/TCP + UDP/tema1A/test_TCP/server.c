#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#define NMAX 100000


int get_int(char *s){
  int i = 0, nr = 0;
  while(s[i]){
    nr = nr * 10 + (s[i++] - '0');
  }
  return nr;
}

struct Conection{
  unsigned int ip;
  int val;
}cons[NMAX], MAXIM;

int maximum_on_ip = -1;

unsigned int total_cons = 0;
unsigned int  dim, new_dim, frec, ip, ind_max;

int get_max_ind(){
  int ind = 0, maxim = -1;
  for(int i = 0; i<total_cons; i++){
    if(cons[i].val > maxim){
      maxim = cons[i].val;
      ind = i;
    }
  }
  return ind;
}


void assign(){
  for(int i = 0; i<NMAX; i++){
    cons[i].ip = 0;
    cons[i].val = 0;
  }
}

int main(int argc, char **args) {
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
  assign();
  while (1) {
    uint16_t a, b, suma;
    c = accept(s, (struct sockaddr *) &client, &l);

  //  if(fork() == 0){
      char* ip = inet_ntoa(client.sin_addr);
      printf("S-a conectat un client cu ip-ul: %s\n", ip);
      // deservirea clientului
      unsigned int val_ip = client.sin_addr.s_addr;
      printf("%lld\n", val_ip);

      if(maximum_on_ip == -1){
        int n = 0;
        n = htonl(n);
        send(c, &n, sizeof(n), 0);
        int dim = strlen(ip);
        int new_dim = dim;
        dim = htonl(dim);
        send(c, &dim, sizeof(dim), 0);
        for(int i = 0; i<new_dim; i++){
          send(c, &ip[i], sizeof(ip[i]), 0);
        }
        maximum_on_ip = 0;
      }
      else{
        int alrd_con = 0;
        for(int i = 0; i<total_cons; i++){
          if(val_ip == cons[i].ip){
            cons[i].val ++;
            alrd_con = 1;
            break;
          }
        }
        if(alrd_con == 0){
          cons[total_cons].ip = val_ip;
          cons[total_cons].val = 1;
          total_cons ++;
        }
        ind_max = get_max_ind();
        ip = cons[ind_max].ip;
        frec = cons[ind_max].val;

        uint32_t ip_send = ip;
        struct in_addr ip_addr;
        ip_addr.s_addr = ip_send;
        char* to_send =  inet_ntoa(ip_addr);

        frec = htonl(frec);
        send(c, &frec, sizeof(frec), 0);
        dim = 9;
        new_dim = dim;
        dim = htonl(dim);
        send(c, &dim, sizeof(dim), 0);
        for(int i = 0; i<new_dim; i++){
          send(c, &to_send[i], sizeof(to_send[i]), 0);
        }

  //    }
  }
    close(c);
    // sfarsitul deservirii clientului;
  }
}
