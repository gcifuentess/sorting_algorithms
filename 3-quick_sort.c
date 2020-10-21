#include "sort.h"
#include <stdio.h>

void quicksort(int *array, size_t size, size_t lo, size_t hi);
size_t partition(int *array, size_t size, size_t lo, size_t hi);
void swap(int *a, int *b, int *array, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the total len of the array
 *
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{

	if (!array || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}

/**
 * quicksort - sorts an array of integers in ascending order
 *             using the Quick sort algorithm with Lamuto partition scheme
 * @array: the array to be sorted
 * @size: the total len of the array
 * @lo: the inferior limit of the subarray
 * @hi: the upper limit of the subarray
 *
 * Return: Void
 */
void quicksort(int *array, size_t size, size_t lo, size_t hi)
{
	size_t p;

	if (lo < hi)
	{
		p = partition(array, size, lo, hi);
		if (p > 0)
			quicksort(array, size, lo, p - 1);
		if (p < size)
			quicksort(array, size, p + 1, hi);
	}
}

/**
 * partition - lamuto partition scheme
 * @array: the array to be sorted
 * @size: the total len of the array
 * @lo: the inferior limit of the subarray
 * @hi: the upper limit of the subarray
 *
 * Return: int index where the partition occurs
 */
size_t partition(int *array, size_t size, size_t lo, size_t hi)
{
	int pivot;
	size_t i, j;

	pivot = array[hi];
	i = lo;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
				swap(array + i, array + j, array, size);
			i++;
		}
	}
	if (i != hi)
		swap(array + i, array + hi, array, size);

	return (i);
}

/**
 * swap - swaps two elements of the array
 * @a: the first element to be swaped with @b
 * @b: the second element to be swaped with @a
 * @array: the array to be sorted
 * @size: the total len of the array
 *
 * Return: Void
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
	print_array((const int *)array, size);
}
