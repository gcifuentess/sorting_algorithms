#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *                  using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: the total len of the array
 *
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	size_t max_limit, i, j;
	int actual, next, swap;

	max_limit = size;

	if (!array || size < 2)
		return;

	for (i = 0; i < max_limit; i++)
	{
		swap = -1;
		actual = array[i];
		for (j = i + 1; j < max_limit; j++)
		{
			next = array[j];
			if (next < actual)
			{
				swap = j;
				actual = array[swap];
			}
		}
		if (swap != -1)
		{
			array[swap] = array[i];
			array[i] = actual;
			print_array(array, size);
		}
	}
}
