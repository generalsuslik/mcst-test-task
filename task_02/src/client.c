#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "erproc.h"

int main()
{
	int serverfd = Socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234);

	Inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
	Connect(serverfd, (struct sockaddr *) &addr, sizeof(addr));

	write(serverfd, "Hello\n", 6);
	
	char buf[1024];
	ssize_t nread = read(serverfd, buf, 1024);
	if (nread == -1) {
		perror("read failed");
		exit(EXIT_FAILURE);
	}

	if (nread == 0) {
		printf("EOF\n");
		exit(EXIT_FAILURE);
	}

	write(STDOUT_FILENO, buf, nread);
	
	sleep(10);
	close(serverfd);

	return 0;
}

