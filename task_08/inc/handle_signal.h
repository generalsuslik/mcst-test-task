#ifndef HANDLE_SIGNAL
#define HANDLE_SIGNAL

#define _POSIX_C_SOURCE 200809L

#include <signal.h>

#define SIZE 1000

void handle_signal(int option);
void handle_sigint(int signum);
void handle_sigint_sa(int signum, siginfo_t *info, void *context);

#endif // HANDLE_SIGNAL

