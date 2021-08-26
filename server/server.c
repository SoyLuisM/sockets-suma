#include <stdio.h>
#include "itoa.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char*argv[]){
    if(argc == 2){
        int fd;
        int puerto = atoi(argv[1]);

        struct sockaddr_in server;
        server.sin_family = PF_INET;
        server.sin_port = htons(puerto);
        server.sin_addr.s_addr = INADDR_ANY;

        if((fd = socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP)) < 0){
            perror("Error al crear el socket\n");
            exit(-1);
        }
        else{
            printf("socket inizializado\n");
        }

        if(bind(fd, (struct sockaddr *)&server,sizeof(struct sockaddr)) < 0){
            printf("socket creado\n");
        }else{
            printf("Error en bind\n");
            exit(-1);
        }
        close(fd);
        printf("bye\n");
    }
    else{
        printf("sintaxis del script\n");
        printf("./Server [puerto] \n");
    }
    return 0;
}