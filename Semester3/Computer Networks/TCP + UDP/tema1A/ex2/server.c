#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main(){

	struct sockaddr_in server, client;
	int l, c, s;

	s = socket(AF_INET, SOCK_STREAM, 0);
	if(s < 0){
		printf("Eroare la crearea socketului server!");
		return 1;
	}
	memset(&server, 0, sizeof(server));
	server.sin_port = htons(1234);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;

	if(bind(s, (struct sockaddr*) &server, sizeof(server)) < 0){
		printf("Eroare la bind!");
		return 1;
	}

	listen(s, 5);

	l = sizeof(client);
	memset(&client, 0, l);

	while(1){
		c = accept(s, (struct sockaddr*) &client, &l);
		printf("Un client nou s-a conectat!\n");
		int nr, nr_sp = 0;
		recv(c, &nr, sizeof(nr), MSG_WAITALL); //primesc prin socketul c, la adresa lui nr, sizeof(nr) bytes si pun flag-ul de asteptarea a datelor
		nr = ntohs(nr);	//convertesc nr din network bytes in host bytes
		for(int i = 0; i<nr; i++){	//de nr ori
			char a;
			recv(c, &a, sizeof(a), MSG_WAITALL);	//citesc un caracter in a
			if(a == ' '){	//daca e spatiu
				nr_sp ++;	//il nuymar
			}
		}
		nr_sp = htons(nr_sp);	//convertesc din host byte in network  bye
		send(c, &nr_sp, sizeof(nr_sp), 0); //trimit prin socketul c, de la adresa nr_sp, sizeof(nr_sp) byes
		close(c); //inchid socketul

	}
	
}
