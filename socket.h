#ifndef SOCKET_H
#define SOCKET_H

void hostSocket(int port);
void closeSocket();
void connectToSocket(const char* ip, int port);

#endif // SOCKET_H