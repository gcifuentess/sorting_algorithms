#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 *                 using the counting sort algorithm
 * @array: the array to be sorted
 * @size: the total len of the array
 *
 * Return: Void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int k, total, i, x;

	if (!array || size < 2)
		return;
	for (i = k = 0; i < (int)size; i++)
	{
		if (k < array[i])
			k = array[i];
	}
	count = calloc(size, sizeof(int) * (k + 1));
	if (!count)
		return;
	output = calloc(size, sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (total = i = 0; i <= k; i++)
	{
		x = count[i];
		count[i] = total;
		total = x + total;
	}
	for (i = 0; i < (int)size; i++)
	{
		x = array[i];
		output[count[x]] = x;
		count[x] += 1;
	}
	print_array(count, k + 1);
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
