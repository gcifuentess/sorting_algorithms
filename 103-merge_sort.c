#include "sort.h"


void clone_array(int *array_a, int *array_b, size_t size);
void split_merge(int *array_b, int *array_a, int min, int max);
void top_down_merge(int *array_a, int *array_b, int min, int mid, int max);

/**
 * merge_sort - sorts an array of integers in ascending order
 *              using the Merge sort algorithm using top-down merge
 * @array: the array to be sorted
 * @size: the total len of the array
 *
 * Return: Void
 */
void merge_sort(int *array, size_t size)
{
	int *arr_b;

	if (!array || size < 2)
		return;

	arr_b = calloc(size, sizeof(int) * size);
	if (!arr_b)
		return;

	clone_array(array, arr_b, size);
	split_merge(arr_b, array, 0, size);

	free(arr_b);
}

/**
 * clone_array - makes a copy of the array_a
 * @array_a: the array to be copied
 * @array_b: the malloc'ed pointer of the size of @array_b
 * @size: the total len of the @array_a
 *
 * Return: Void
 */
void clone_array(int *array_a, int *array_b, size_t size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		array_b[i] = array_a[i];
}

/**
 * split_merge - splits the array
 * @array_a: the original array
 * @array_b: the cloned array
 * @min: the lower limit
 * @max: the upper limit
 *
 * Return: Void
 */
void split_merge(int *array_b, int *array_a, int min, int max)
{
	int mid;

	if (max - min <= 1)
		return;

	mid = (min + max) / 2;

	split_merge(array_a, array_b, min, mid);
	split_merge(array_a, array_b, mid, max);

	top_down_merge(array_b, array_a, min, mid, max);
}

/**
 * top_down_merge - merges and sort the splited arrays
 * @array_a: the original array
 * @array_b: the cloned array
 * @min: the lower limit
 * @max: the upper limit
 * @mid: the middle of the split
 *
 * Important:
 *            Left source half is  array_a[min : mid-1]
 *            Right source half is array_a[mid : max-1]
 *            Result is            array_b[min : max-1]
 *
 * Return: Void
 */
void top_down_merge(int *array_a, int *array_b, int min, int mid, int max)
{
	int i, j, k;

	i = min;
	j = mid;

	printf("Merging...\n");
	/* While there are elements in the left or right runs...*/
	for (k = min; k < max; k++)
	{
		/* If left run head exists and is <= existing right run head*/
		if (i < mid && (j >= max || array_a[i] <= array_a[j]))
		{
			array_b[k] = array_a[i];
			i++;
			/*printf("[left]: %d\n", array_b[k]);*/
		}
		else
		{
			array_b[k] = array_a[j];
			j++;
			/*printf("[right]: %d\n", array_b[k]);*/
		}
	}
	printf("[left]: ");
	print_array(array_a + min, i - min);

	printf("[right]: ");
	print_array(array_a + mid, j - mid);

	printf("[Done]: ");
	print_array(array_b + min,  max - min);

}
