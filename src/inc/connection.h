#ifndef SRC_INC_CONNCETION_H_
#define SRC_INC_CONNCETION_H_

#include <sys/socket.h>
#include <sys/types.h>

class Connection{

    private:
        int socket_fd;
    public:
    Connection();
    ~Connection();

    /* socket creation and bind data */
    int InitSocket(unsigned int port, char *addr);

    /* wait for conncetion */
    int Listen();

    /* connect to server */
    int Connect();
}

#endif  // SRC_INC_CONNCETION_H_