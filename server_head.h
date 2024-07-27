/* Membuat server yang mempunyai fitur
    menerinm file, menerima client, menolak client,
    memutus jaringan, menampilkan informasi client  */

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <strings.h>
#include <netinet/in.h>
#include <unistd.h>
#include <asm-generic/socket.h>


int server_fd, new_server;
struct sockaddr_in address;
int opt = 1;
socklen_t addrlen = sizeof(address);
char* Buffer[1024] = {0};
int PORT = 6969;


/*Main Server*/

void newServer(){
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
}

int newSockopt(){
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(address));
    return 0;
}
int setAddressin(){
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = PORT;
    address.sin_family = AF_INET;
}

int setBind(){
    if(bind(server_fd, (struct sockaddr*)&address, sizeof(addrlen)) < 0){
        perror("Bind Error");
        exit(EXIT_FAILURE);
    }
}

int setListen(){
    if(listen(server_fd, 5) < 0 ){
        perror("Listen Error");
        exit(EXIT_FAILURE);
    }
}

int setAccept(){
    if(accept(new_server, (struct sockaddr*)&address, &addrlen) < 0){
        perror("Accept error");
        exit(EXIT_FAILURE);
    }
}










