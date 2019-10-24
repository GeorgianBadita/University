#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main(){
	struct sockaddr_in server;
	int c;

	c = socket(AF_INET, SOCK_STREAM, 0);

	if(c < 0){
		printf("Eroare la crearea socketului cleint!\n");
		return 1;
	}

	memset(&server, 0, sizeof(server));
	server.sin_port = htons(1234);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(c, (struct sockaddr*) &server, sizeof(server)) < 0){
		printf("Eroare la conectarea la server\n");
		return 1;
	}
	
	char str[100];
	int num = 0;
	while(1){
		char chr;
		scanf("%c", &chr);	//citesc pe rand cate un cracter
		str[num] = chr;	//il pun in sirul str
		num++;	
		if(chr == '0'){	//daca cracterul e 0
			str[num] = '\0';	//pun NULL pe ultima pozitie
			break;	//ma opresc
		}
	}
	int new_num = htons(num);	//convertesc lungimea din host bytes in network bytes
	send(c, &new_num, sizeof(new_num), 0); //trimit prin socketul c de la adresa lui new_num, sizeof(new_num) bytes
	for(int i =  0; i<num; i++){	//de num ori
		char chr = str[i];
		send(c, &chr, sizeof(chr), 0);	//trimit cate un caracter prin socketul c
	}
	int nr;
	recv(c, &nr, sizeof(nr), 0); //primesc de la server, prin socketul c, de la adresa lui nr, sizeof(nr) bytes
	nr = ntohs(nr); //convertesc din newtork bytes in host bytes
	printf("Numarul de spatii este: %d", nr); //afisez numarul de spatii
	close(c); //inchid socketul
}
