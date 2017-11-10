#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "IRCServer.h"

using namespace std;

int QueueLength = 5;

int main() {
}

int IRCServer::open_server_socket(int port) {
	// Set the IP address and port for this server
	struct sockaddr_in serverIPAddress;
	memset(&serverIPAddress, 0, sizeof(serverIPAddress));
	serverIPAddress.sin_family = AF_INET;
	serverIPAddress.sin_addr.s_addr = INADDR_ANY;
	serverIPAddress.sin_port = htons((u_short) port);

	// Allocate a socket
	int masterSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (masterSocket < 0) {
		perror("socket");
		exit (-1);
	}

	// Set socket options to reuse port.
	// Otherwise we will have to wait about 2 minutes before reusing the same port number
	// UNUSED VARIABLES
	//	int optval = 1;
	//	int err = setsockopt(masterSocket, SOL_SOCKET, SO_REUSEADDR,
	//				(char *) &optval, sizeof(int));

	// Bind the socket to the IP address and port
	int error = bind (masterSocket,
				(struct sockaddr *) &serverIPAddress,
				sizeof(serverIPAddress));
	if (error) {
		perror("bind");
		exit (-1);
	}
	
	// Put socket in listening mode and set the size of the queue of unprocessed connections
	error = listen (masterSocket, QueueLength);
	if (error) {
		perror("listen");
		exit (-1);
	}

	return masterSocket;
}
