#include "sort.h"

int knuth_sequence(int len);
void insertion_sort_array(int *array, size_t size);
void swap(int *a, int *b);

/**
 * shell_sort - sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth Sequence
 * @array: the array to be sorted
 * @size: the total len of the array
 *
 * Return: Void
 */
void shell_sort(int *array, size_t size)
{
	int gap, len, module, sub_len, curr, next, i, j;

	len = (int)size;
	gap = knuth_sequence(len);

	while (gap > 1)
	{
		module = len % gap;
		for (i = 0; i < gap; i++)
		{
			if (module-- > 0)
				sub_len = len / gap;
			else
				sub_len = len / gap - 1;

			while (sub_len--)
			{
				for (j = 0; j <= sub_len; j++)
				{
					curr = array[i + j * gap];
					next = array[i + (j + 1) * gap];
					if (next < curr)
					{
						array[i + j * gap] = next;
						array[i + (j + 1) * gap] = curr;
					}
				}
			}
		}
		gap /= 3;
		print_array(array, size);
	}
	insertion_sort_array(array, size);
	print_array(array, size);
}

/**
 * knuth_sequence - returns the biggest number in the knuth
 *                  secuence lower than len
 * @len: is the len of the array to be sorted with shell sort.
 *
 * Return: the biggest posible number of knuth sequence
 */
int knuth_sequence(int len)
{
	int gap;

	for (gap = 0; gap < len;)
		gap = gap * 3 + 1;
	gap /= 3;

	return (gap);
}

/**
 * insertion_sort_array - sorts an array integers in ascending order
 *                       using the Insertion sort algorithm
 * @array: the array to be sorted
 * @size: the total len of the array
 *
 * Return: Void
 */
void insertion_sort_array(int *array, size_t size)
{
	int len, i, j, actual, next;
	int *pivot;

	len = (int)size;
	for (i = 0; i < (len - 1); i++)
	{
		actual = array[i];
		next = array[i + 1];
		if (actual > next)
		{
			pivot = array + i;
			swap(pivot, pivot + 1);
			for (j = i; j > 0; j--)
			{
				actual = array[j];
				next = array[j - 1];
				pivot = array + j;
				if (actual < next)
					swap(pivot - 1, pivot);
				else
					break;
			}
		}
	}
}

/**
 * swap - swaps two elements of the array
 * @a: the first element to be swaped with @b
 * @b: the second element to be swaped with @a
 *
 * Return: Void
 */
void swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
