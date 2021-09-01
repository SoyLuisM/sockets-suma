#include <stdio.h>
#include "itoa.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define MAXLINES 1024
  
int main(int argc, char *argv[]) {
    if(argc == 2){
        int sock_cli_fd,sock_serv_fd;
        int PORT = atoi(argv[1]);
        char msg[] = "15";
        int size_dgram;
        int result = 0;
        char buffer[MAXLINES];

        struct sockaddr_in server;
        
        server.sin_family = PF_INET;
        server.sin_port = htons(PORT);
        server.sin_addr.s_addr = INADDR_ANY;

        if( (sock_cli_fd = socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP)) < 0){
            perror("Error al crear el socket\n");
            exit(-1);
        }
        else{
            printf("socket inizializado\n");
        }
        do{
            printf("ingrese un numero\n");
            scanf("%s",msg);
            sendto(sock_cli_fd, (const char *)msg, strlen(msg), MSG_CONFIRM, (const struct sockaddr *) &server, sizeof(server));

            printf("ingrese un numero\n");
            scanf("%s",msg);
            sendto(sock_cli_fd, (const char *)msg, strlen(msg), MSG_CONFIRM, (const struct sockaddr *) &server, sizeof(server));
            
            printf("ingrese un numero\n");
            scanf("%s",msg);
            sendto(sock_cli_fd, (const char *)msg, strlen(msg), MSG_CONFIRM, (const struct sockaddr *) &server, sizeof(server));

            printf("ingrese un numero\n");
            scanf("%s",msg);
            sendto(sock_cli_fd, (const char *)msg, strlen(msg), MSG_CONFIRM, (const struct sockaddr *) &server, sizeof(server));

            printf("mensaje enviado\n");

            size_dgram = recvfrom(sock_cli_fd,(char *)buffer, MAXLINES, MSG_WAITALL, (struct sockaddr *)&server,&sock_serv_fd);
            printf("el mensaje del servidor es %s\n", buffer);
            result = atoi(buffer);

            if(result == -1){
                printf("el resultado no es valido\n");
                sleep(1);
                //system("clear");
            }else{
                printf("el resultado es correcto\n");
            }
            close(sock_serv_fd);
        }while(result == -1);
    }else{
        printf("sintaxis del script\n");
        printf("./Client num_puerto \n");
    }
    return 1;
}