#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                using counting sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max, *count, *sorted;
	size_t ii;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	/* Find the maximum value in the array */
	max = array[0];
	for (ii = 1; ii < size; ii++)
	{
		if (array[ii] > max)
			max = array[ii];
	}
	/* Create a count array to store the count of each element */
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
	{
		free(sorted);
		return;
	}
	/* Initialize count array */
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	/* Count occurrences of each element */
	for (ii = 0; ii < size; ii++)
		count[array[ii]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	/* Update the input array with sorted values */
	for (ii = 0; ii < size; ii++)
	{
		sorted[count[array[ii]] - 1] = array[ii];
		count[array[ii]] -= 1;
	}
	for (ii = 0; ii < size; ii++)
		array[ii] = sorted[ii];
	free(sorted);
	free(count);
}
