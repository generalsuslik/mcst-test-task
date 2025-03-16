#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int fd = open("file.txt", O_RDONLY);
	if (fd == -1) {
		printf("errno = %d\n", errno);

		printf("Error message: %s\n", strerror(errno)); // sys_errlist is deprecated

		perror("open sys call error");

		exit(EXIT_FAILURE);
	}	

	printf("Opened successfully\n");
	close(fd);

	return 0;
}

