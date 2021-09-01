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
        int sock_serv_fd, sock_cli_fd;
        int size_dgram;
        int PORT = atoi(argv[1]);
        char buffer[MAXLINES];
        int num[MAXLINES];
        int result = 0;

        struct sockaddr_in server;
        struct sockaddr_in client;

        server.sin_family = PF_INET;
        server.sin_port = htons(PORT);
        server.sin_addr.s_addr = INADDR_ANY;

        sock_cli_fd = sizeof(client);

        if( (sock_serv_fd = socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP)) < 0){
            perror("Error al crear el socket\n");
            exit(-1);
        }
        else{
            printf("socket inizializado\n");
        }

        if(bind (sock_serv_fd, (struct sockaddr *)&server, sizeof(struct sockaddr)) < 0){
            printf("Error en bind\n");
            exit(-1);
        }else{
            printf("socket creado\n");
        }
        
        while(1){
            // sleep(1);
            // system("clear");
            printf("Esperando una nueva conexion\n");

            size_dgram = recvfrom(sock_serv_fd,(char *)buffer, MAXLINES, MSG_WAITALL, (struct sockaddr *)&client,&sock_cli_fd);
            buffer[size_dgram] = '\0';

            num[1]=atoi(buffer);

            size_dgram = recvfrom(sock_serv_fd,(char *)buffer, MAXLINES, MSG_WAITALL, (struct sockaddr *)&client,&sock_cli_fd);
            buffer[size_dgram] = '\0';

            num[2]=atoi(buffer);

            size_dgram = recvfrom(sock_serv_fd,(char *)buffer, MAXLINES, MSG_WAITALL, (struct sockaddr *)&client,&sock_cli_fd);
            buffer[size_dgram] = '\0';

            num[3]=atoi(buffer);

            size_dgram = recvfrom(sock_serv_fd,(char *)buffer, MAXLINES, MSG_WAITALL, (struct sockaddr *)&client,&sock_cli_fd);
            buffer[size_dgram] = '\0';

            num[4]=atoi(buffer);

            result = num[1] + num [4];
            result *= num[2];
            result -= num[3];

            printf("mensaje del cliente: %d %d %d %d %d\n",result, num[1],num[2], num[3],num[4]);
            if(result>=500){
                itoa_(result,buffer);
                printf("el resultado es valido\n");
            }else{
                result = -1;
                itoa_(result,buffer);
                printf("el resultado no es valido %s\n",buffer);
            }
            sendto (sock_serv_fd, (char *)&buffer, sizeof(buffer), 0, (struct sockaddr *)&client, sock_cli_fd);
            printf("bye\n");
            close(sock_cli_fd);
            
            
        }
        close (sock_serv_fd);
    }
    else{
        printf("sintaxis del script\n");
        printf("./Server num_puerto \n");
    }
    return 1;
}