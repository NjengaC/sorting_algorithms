#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * lomuto_partition - Partitions an array using Lomuto's scheme.
 * @array: The array to partition.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 * Return: The pivot index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			Swap(&array[i], &array[j]);
			/*print_array_(array, size);*/
		}
	}

	Swap(&array[i + 1], &array[high]);
	print_array_(array, size);

	return i + 1;
}

/**
 * lomuto_quicksort - Sorts an array using the quicksort algorithm with Lomuto's scheme.
 * @array: The array to sort.
 * @low: The low index of the array.
 * @high: The high index of the array.
 * @size: The size of the array.
 */
void lomuto_quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		lomuto_quicksort(array, low, pivot - 1, size);
		lomuto_quicksort(array, pivot + 1, high, size);
	}
}

/**
 *  * quick_sort - Initiates the quicksort algorithm with Lomuto's scheme.
 *   * @array: The array to sort.
 *    * @size: The size of the array.
 *     */
void quick_sort1(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quicksort(array, 0, size - 1, size);
}

/**
 * print_array - Prints an array of integers.
 * @array: The array to be printed.
 * @size: Number of elements in @array.
 */
void print_array_(const int *array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}
