#ifndef SOCKET_H
#define SOCKET_H

void hostSocket(int port);
void closeSocket();
void connectToSocket(const char* ip, int port);
void sendData(char* data);

#endif // SOCKET_H