#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdio.h>


int get_int(char* arg){
	int num = 0;
	int i;
	for(i = 0; i<strlen(arg); i++){
		num = num*10 + arg[i] - '0';
	}
	return num;
}


int main(int argc, char** arg){
	int s;
	struct sockaddr_in server, client;
	int l, c;

	s = socket(AF_INET, SOCK_STREAM, 0);

	if(s < 0){
		printf("Eroare la crearea socketului server!\n");
		return 1;
	}

	memset(&server, 0, sizeof(server));
	server.sin_port = htons(get_int(arg[1]));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;

	if(bind(s,(struct sockaddr*) &server, sizeof(server)) < 0){
		printf("Eroare la bind!\n");
		return 1;
	}

	listen(s, 5);

	l = sizeof(client);
	memset(&client, 0, sizeof(client));

	while(1){
		int suma = 0, nr = 0;
		c = accept(s, (struct sockaddr*) &client, &l);
		printf("S-a conectat un client.\n");
		recv(c, &nr, sizeof(nr), MSG_WAITALL);
		nr = ntohs(nr);
		for(int i = 0; i<nr; i++){
			int a;
			recv(c, &a, sizeof(a), MSG_WAITALL);
			a = ntohs(a);
			suma += a;
		}
		suma = htons(suma);
		send(c, &suma, sizeof(suma), 0);
		close(c);
	}
}
