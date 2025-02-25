#include "../inc/sort.h"

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void sort(int *arr, size_t n) 
{
	size_t left = 0;
	size_t right = n - 1;

	th_params *params = malloc(sizeof(th_params));
	params->arr = arr;
	params->left = left;
	params->right = right;

	pmerge_sort(params);

	free(params);
}

void *pmerge_sort(void *args)
{
	th_params* params = (th_params *) args;
	int *arr     = params->arr;
	size_t left  = params->left;
	size_t right = params->right;

	if (left >= right) {
		return NULL;
	}

	// if arr's len is <= MIN_SIZE we ain't gonna parallel the sorting task
	if (right - left + 1 <= MIN_SIZE) {
		merge_sort(arr, left, right);
		free(params);
		return NULL;
	}

	size_t mid = left + (right - left) / 2;

	th_params *left_params = malloc(sizeof(th_params));
	left_params->arr   = arr;
	left_params->left  = left;
	left_params->right = mid;

	th_params *right_params = malloc(sizeof(th_params));
	right_params->arr   = arr;
	right_params->left  = mid + 1;
	right_params->right = right;

	pthread_t tid_left;
	pthread_t tid_right;
	
	int err = 0;
	err = pthread_create(&tid_left, NULL, pmerge_sort, left_params);
	if (err != 0) {
		perror("[pmerge_sort] Error creating the left thread");
		exit(EXIT_FAILURE);
	}

	err = pthread_create(&tid_right, NULL, pmerge_sort, right_params);
	if (err != 0) {
		perror("[pmerge_sort] Error creating the right thread");
		exit(EXIT_FAILURE);
	}

	pthread_join(tid_left, NULL);
	pthread_join(tid_right, NULL);

	merge(arr, left, mid, right);

	return NULL;
}

void merge_sort(int *arr, size_t left, size_t right)
{
	if (left >= right) {
		return;
	}

	size_t mid = left + (right - left) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);

	merge(arr, left, mid, right);
}

void merge(int *arr, size_t left, size_t mid, size_t right)
{
	size_t i = left;
	size_t j = mid + 1;
	size_t k = 0;

	size_t len = right - left + 1;
	int *temp = malloc(len * sizeof(int));

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= right) {
		temp[k++] = arr[j++];
	}

	for (i = left, k = 0; i <= right; ++i, ++k) {
		arr[i] = temp[k];
	}

	free(temp);
}

