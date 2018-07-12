#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

#include <string.h>

#include "inc/connection.h"

enum Error{
    SUCCSSED,
    FAILURE,
    SOCKET_CREATION_FAILURE,
    BAD_STATE
};

LinSocket::LinSocket(){
    state = NOT_INIT;
}

int LinSocket::InitSocket(unsigned int port, char *ipv4_addr){

    if(state != NOT_INIT){
        return BAD_STATE;
    };

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;  // IPv4
    addr.sin_port = htons(port);
    
    inet_pton(AF_INET, ipv4_addr, &(addr.sin_addr.s_addr));
    

    int r = socket(AF_INET, SOCK_STREAM, 0);
    if(r){
        return SOCKET_CREATION_FAILURE;
    }
    this->socket_fd = r;

    return SUCCSSED;
}