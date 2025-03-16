#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "erproc.h"

#define SERVER_PORT 1234
#define LISTENERS   7
#define BUF_SIZE    1024

int main()
{
	int serverfd = Socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port   = htons(SERVER_PORT);

	Bind(serverfd, (struct sockaddr *) &addr, sizeof(addr));
	Listen(serverfd, LISTENERS);

	socklen_t addrlen = sizeof(addr);
	int clientfd = Accept(serverfd, (struct sockaddr *) &addr, &addrlen);
	
	char buf[BUF_SIZE];
	ssize_t nread = read(clientfd, buf, BUF_SIZE);
	if (nread == -1) {
		perror("Failed to read from client");
		exit(EXIT_FAILURE);
	}

	if (nread == 0) {
		printf("EOF\n");
	}

	write(STDOUT_FILENO, buf, nread);
	write(clientfd, buf, nread);

	sleep(15);

	shutdown(serverfd, SHUT_RDWR);
	close(clientfd);
	close(serverfd);

	return 0;
}

