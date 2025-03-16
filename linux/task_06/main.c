#include "file_info.h"

#include <stdio.h>
#include <stdlib.h>

int main(const int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s <file_path>\n", argv[0]);
		exit(EXIT_FAILURE);
	}	

	int err = print_info(argv[1]);
	if (err == -1) {
		exit(EXIT_FAILURE);
	}

	return 0;
}

