#include <../include/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_BUS "/dev/i2c-1"
#define SLAVE_ADDR 0x69 // MC-BALIE

#define PORT 8080

int setupI2C(const char *bus, int slave_addr) {
    int file = open(bus, O_RDWR);
    ioctl(file, I2C_SLAVE, slave_addr);
    return file;
}


int main() {
    hostSocket(PORT);

    int file;
    char *bus = I2C_BUS;
    unsigned char buffer[60];
    file = setupI2C(bus, SLAVE_ADDR);
    while (1)
    {
        acceptConnection();
        if (read(file, buffer, sizeof(buffer)) > 0) {
            printf("Data read: %s\n", buffer);
            if (buffer[0] == '1') {
                sendData("1")
                write(file, buffer, 1);
            } else if (buffer[0] == '0') {
                sendData("0")
            }
        }


        
    }
    
    return 0;
}