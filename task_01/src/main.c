#include "sort.h"

#include <stdio.h>

int main()
{
	int arr[] = { 2, 9, 1, 0, 5, -1, 55, 12, 666, 8, -123, 52, 52, 121 };
	size_t n = sizeof(arr) / sizeof(int);

	sort(arr, n);

	for (size_t i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

