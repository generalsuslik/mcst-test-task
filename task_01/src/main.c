#include "sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(const int argc, char *argv[])
{
	ssize_t n = 100;
	if (argc == 2) {
		n = atol(argv[1]);
	}

	int arr[n];
	for (ssize_t i = n - 1; i >= 0; --i) {
		arr[i] = i;
	}
	
	sort(arr, n);

	for (ssize_t i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

