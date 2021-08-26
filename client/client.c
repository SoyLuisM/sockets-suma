#include <stdio.h>
#include "itoa.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char*argv[]){
    printf("hola soy el cliente\n");
    return 0;
}