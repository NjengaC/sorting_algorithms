#include "sort.h"

/**
 * swap - swaps the order of ints in an array
 * @large: large int
 * @small: smaller int
 * Return: nothing
 */

void swap(int *large, int *small)
{
	int temp;

	temp = *large;
	*large = *small;
	*small = temp;
}

/**
 * bubble_sort - sorts an array of ints in ascending order
 * @array: array of ints
 * @size: size of the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swaps = 0;

	if (!array || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swaps = 1;
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
		if (swaps == 0)
			break;
	}
}
/* later tests - array with mixed characters, strings, sorted array*/
