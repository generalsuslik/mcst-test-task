#ifndef SORT_H
#define SORT_H

#include <stddef.h>

#define MIN_SIZE 5 // arrays with len <= MIN_SIZE will not be sorted parallely

typedef struct {
	int    *arr;
	size_t left;
	size_t right;
} th_params;


/**
 * @brief Performes sort (prepares data & calls pmerge_sort) on the int array  
 *
 * @param arr - incomming array (pointer to it's first element)
 */
void sort(int *arr, size_t n);

/**
 * @brief Performes parallel merge sort 
 *
 * @param args - struct th_params, contains ptr to arr, left & right bounds
 * @return returns NULL (pthread.h requirements)
 */
void *pmerge_sort(void *args);

/**
 * @brief Performes simple merge sort on array len <= MIN_SIZE
 * 
 * @param arr - incomming array (pointer to it's first element)
 * @param left - left bound of the sorted part of the array
 * @param right - right bound of the sorted part of the array
 */
void merge_sort(int *arr, size_t left, size_t right);

/**
 * @brief Merges array's parts from left to mid and from mid + 1 to right
 * into 1 sorted array
 *
 * @param left - left bound of the sorted part of the array
 * @param mid - mid bound of the sorted part of the array
 * @param right - right bound of the sorted part of the array
 */
void merge(int *arr, size_t left, size_t mid, size_t right);

#endif // SORT_H
	   
