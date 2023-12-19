#include "sort.h"

/**
 * partition - partitions an array of integers using Lomuto partiton scheme
 * @array: The array
 * @low: lower index of the partition
 * @high: higher end index
 * @size: size of array
 * Return: pivot index.
 */
int partition(int *array, int low, int high, size_t size)
{

	int pivot = array[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);


		Swap(&array[i], &array[j]);
		print_array(array, size);
	}
}


/**
 * quicksort - sorts an array using the quicksort algorithm.
 * @array: array
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: nothing
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		quicksort(array, low, pivot, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - main function calling
 * @array: the array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
