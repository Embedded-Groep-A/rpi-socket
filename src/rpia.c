#include <../include/socket.h>
#include <stdio.h>

#define PORT 8380

int main() {
    hostSocket(PORT);
    while (1)
    {
        acceptConnection();
        char *data = listenForData();
        printf("%s\n", data);
        // if (data != NULL)
        // {
        //     printf("Data received: %s\n", data);
        // }
    }
    
    return 0;
}