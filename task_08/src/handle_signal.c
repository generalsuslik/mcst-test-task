#include "handle_signal.h"

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int sigint_count = 0;
int curr_row     = 0;
int curr_col     = 0;

void handle_signal(int option)
{
	static int A[SIZE][SIZE];
	static int B[SIZE][SIZE];
	static int C[SIZE][SIZE]; // res;
	
	for (size_t i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			A[i][j] = 1;
			B[i][j] = 2;
			C[i][j] = 0;
		}
	}

	if (option == 0) {
		signal(SIGINT, handle_sigint);
	} else {
		struct sigaction sa;
		sa.sa_sigaction = handle_sigint_sa;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGINT, &sa, NULL);
	}
	
	extern int curr_row;
	extern int curr_col;

	for (size_t i = 0; i < SIZE; ++i) {
		for (size_t j = 0; j < SIZE; ++j) {
			curr_row = i;
			curr_col = j;
			for (int k = 0; k < SIZE; ++k) {
				C[i][j] += A[i][k] + B[k][j];
			}
			sleep(1);
		}
	}

	printf("Multiplication completed\n");
}

void handle_sigint(int signum __attribute__((unused)))
{
	if (sigint_count == 0) {
		printf("[signal] Received SIGINT\n");
		printf("Current positions: row = %d, col = %d\n", curr_row, curr_col);
		fflush(stdout);
		signal(SIGINT, SIG_DFL);
	}

	++sigint_count;
}

void handle_sigint_sa(int signum __attribute__((unused)), 
					  siginfo_t *info __attribute__((unused)), 
					  void *context __attribute__((unused)))
{
	if (sigint_count == 0) {
		printf("[sigaction] Recived SIGINT\n");
		printf("Current positions: row = %d, col = %d\n", curr_row, curr_col);
		fflush(stdout);
		struct sigaction sa_default;
		sa_default.sa_handler = SIG_DFL;
		sigemptyset(&sa_default.sa_mask);
		sa_default.sa_flags = 0;
		sigaction(SIGINT, &sa_default, NULL);
	}
	
	++sigint_count;
}


