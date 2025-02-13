#include <../include/socket.h>
#include <stdio.h>
#include <unistd.h>

#define IP "145.52.127.118"
#define HOST "rpia.local"
#define PORT 8080

int main() {
    connectToSocket(HOST, PORT);
    sleep(1);
    sendData("Hello world");
    closeSocket();

    return 0;
}