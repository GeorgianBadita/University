#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>

int get_int(char* arg){
	int num = 0;
	int i;
	for(i = 0; i<strlen(arg); i++){
		num = num*10 + arg[i] - '0';
	}
	return num;
}

int main(int argc, char** arg){
	int c;
	struct sockaddr_in server;
	int *sir, num, sum = 0;

	printf("Dari numarul de numere: ");
	scanf("%d", &num);
	sir = (int*)malloc(num*sizeof(int));

	for(int i = 0; i<num; i++){
		printf("Dati sir[%d]: ", i);
		scanf("%d", &sir[i]);
	}

	c = socket(AF_INET, SOCK_STREAM, 0);

	if(c < 0){
		printf("Eroare la crearea socketului client!\n");
		return 1;
	}

	memset(&server, 0, sizeof(server));
	server.sin_port = htons(get_int(arg[1]));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(c, (struct sockaddr*) &server, sizeof(server)) < 0){
		printf("Eroare conectare la server\n");
		return 1;
	}
	int new_num = htons(num);
	send(c, &new_num, sizeof(new_num), 0);
	for(int i = 0; i<num; i++){
		int elem = htons(sir[i]);
		send(c, &elem, sizeof(elem), 0);
	}

	recv(c, &sum, sizeof(sum), 0);
	sum = ntohs(sum);
	printf("Suma este: %d", sum);
	close(c);

}
