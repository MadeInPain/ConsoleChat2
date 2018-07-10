#include "inc/connection.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>

int Connection::InitSocket(unsigned int port_, char *addr_){

    struct addrinfo hints;

    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_UNSPEC;  // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;  // TCP
    hints.ai_flags = 0;
    hints.ai_protocol = 0;  // Any protocol    
    

    // man getaddrinfo !!!
    int r = socket(AF_INET, SOCK_STREAM, 0);
}