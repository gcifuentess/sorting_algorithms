#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: the total len of the array
 *
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
	size_t max_limit, i;
	int actual, next;

	if (!array || !size)
		return;

	max_limit = size - 1;
	while (max_limit)
	{
		for (i = 0; i < max_limit; i++)
		{
			actual = array[i];
			next = array[i + 1];
			if (next < actual)
			{
				array[i] = next;
				array[i + 1] = actual;
				print_array(array, size);
			}
		}
		max_limit -= 1;
	}
}
