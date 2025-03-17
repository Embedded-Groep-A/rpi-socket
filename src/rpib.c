#include <../include/socket.h>
#include <stdio.h>
#include <unistd.h>

#define IP "145.52.127.118"
#define IP_LOCAL "127.0.0.1"
#define HOST "rpia.local"
#define PORT 8380

int main() {
    connectToSocket(IP_LOCAL, PORT);
    sleep(1);
    sendData("Hello world");
    closeSocket();

    return 0;
}