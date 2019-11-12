#include <stdio.h>
#include <string.h>
#include <rpc.h>
#include <stdint.h>
#include <winsock2.h>
#include <io.h>

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
    char* str = (char*)malloc(5* sizeof(char));
    char* rec = (char*)malloc(5* sizeof(char));
    str[0] = 't';
    str[1] = 'e';
    str[2] = 'i';
    str[3] = 'u';
    str[4] = '\0';
    while (1) {
        uint16_t a, b, suma;
        c = accept(s, (struct sockaddr *) &client, &l);
        printf("S-a conectat un client.\n");
        // deservirea clientului
        recv(c, rec, 4*sizeof(char), MSG_WAITALL);
        printf("%s\n", rec);
        close(c);
        // sfarsitul deservirii clientului;
    }
}