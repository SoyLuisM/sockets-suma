#include <stdio.h>
#include "itoa.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define MAXLINES 1024

int main(int argc, char*argv[]){
    if(argc == 2){
        int socket_server, socket_client;
        int size_dgram;
        int puerto = atoi(argv[1]);
        char buffer[MAXLINES];

        struct sockaddr_in server;
        struct sockaddr_in client;
        server.sin_family = PF_INET;
        server.sin_port = htons(puerto);
        server.sin_addr.s_addr = INADDR_ANY;

        socket_client = sizeof(socket_client);

        if( (socket_server = socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP)) < 0){
            perror("Error al crear el socket\n");
            exit(-1);
        }
        else{
            printf("socket inizializado\n");
        }

        if(bind (socket_server, (struct sockaddr *)&server, sizeof(struct sockaddr)) < 0){
            printf("socket creado\n");
        }else{
            printf("Error en bind\n");
            exit(-1);
        }

        size_dgram = recvfrom(socket_server,(char *)buffer, MAXLINES, MSG_WAITALL, (struct sockaddr *)&client,&socket_client);
        // buffer[size_dgram] = "\n";
        printf("mensaje del cliente: %s\n",buffer);
        close (socket_server);
        printf("bye\n");
    }
    else{
        printf("sintaxis del script\n");
        printf("./Server [puerto] \n");
    }
    return 0;
}