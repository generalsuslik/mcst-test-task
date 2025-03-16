#include "handle_signal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIGNAL_PROC "sig"
#define SIGACT_PROC "sa"

void help(char *argv0)
{
	printf("Usage: %s [-f <function>]\n", argv0);
	printf("  -f <function>: function is either 'sig' (for signal) or 'sa' (for sigaction)\n");
}

int main(const int argc, char *argv[])
{

	if (argc != 3) {
		help(argv[0]);
		exit(EXIT_FAILURE);
	}

	int opt;
	char *func = NULL;

	while ((opt = getopt(argc, argv, "f:")) != -1) {
		switch (opt) {
			case 'f':
				func = optarg;
				break;

			default:
				exit(EXIT_FAILURE);
		}
	}

	if (strcmp(func, "sig") == 0) {
		handle_signal(0);
	} else if (strcmp(func, SIGACT_PROC) == 0) {
		handle_signal(1);
	} else {
		help(argv[0]);
		exit(EXIT_FAILURE);
	}


	return 0;
}


