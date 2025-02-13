#include <../include/socket.h>
#include <stdio.h>

#define PORT 8080

int main() {
    hostSocket(PORT);
    printf(listenForData());
    return 0;
}