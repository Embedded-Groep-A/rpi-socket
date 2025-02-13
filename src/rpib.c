#include <../include/socket.h>
#include <stdio.h>  

#define IP "145.52.127.118"
#define PORT 8080

int main() {
    connectToSocket(IP, PORT);
    sendData("Hello world");
    closeSocket();

    return 0;
}