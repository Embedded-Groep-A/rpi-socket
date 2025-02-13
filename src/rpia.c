#include <../include/socket.h>
#include <stdio.h>

#define PORT 8080

int main() {
    hostSocket(PORT);
    while (1)
    {
        printf("Data received: %s\n", listenForData());
    }
    
    return 0;
}