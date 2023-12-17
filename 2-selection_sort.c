#include "sort.h"

/**
 * swap - swaps two array ints positions
 * @left: int on the sorted portion
 * @right: int at unsorted portion
 * Return: nothing
 */
void sswap(int *left, int *right)
{
	int temp;

	temp = *left;
	*left = *right;
	*right = temp;
}

/**
 * selection_sort - sorts an array of ints in an ascending order
 * @array: the array
 * @size: size of the array
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k, swaps;

	if (!array || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		k = i;
		swaps = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
			{
				swaps = 1;
				k = j;
			}
		}
		if (swaps == 1)
		{
			sswap(&array[i], &array[k]);
			print_array(array, size);
		}
	}
}
