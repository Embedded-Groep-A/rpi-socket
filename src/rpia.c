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

// Function to set up I2C bus and address
int setupI2C(const char *bus, int slave_addr) {
    int file = open(bus, O_RDWR);
    if (file < 0) {
        perror("Failed to open I2C bus");
        exit(1);
    }
    if (ioctl(file, I2C_SLAVE, slave_addr) < 0) {
        perror("Failed to set I2C address");
        exit(1);
    }
    return file;
}

// Main function that handles both I2C communication and socket connection
int main() {
    hostSocket(PORT);  // Setup socket
    int file;
    unsigned char buffer[60];  // Buffer for I2C data

    // Set up the I2C bus and address
    file = setupI2C(I2C_BUS, SLAVE_ADDR);
    
    while (1) {
        acceptConnection();  // Accept a connection on the socket
        
        // Read data from I2C device
        int bytesRead = read(file, buffer, sizeof(buffer));
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';  // Ensure null-terminated string
            
            printf("Data read from I2C: %s\n", buffer);
            
            if (buffer[0] == '1') {
                sendData("1");  // Send data to client
                write(file, buffer, 1);  // Send data back to I2C device
            } else if (buffer[0] == '0') {
                sendData("0");  // Send data to client
            } else {
                sendData("Unknown command");
            }
        } else if (bytesRead < 0) {
            perror("I2C read error");
        }

        // Add any additional handling here (e.g., timeout or error handling)
    }
    
    close(file);  // Close the I2C bus
    return 0;
}
