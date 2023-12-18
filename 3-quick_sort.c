#include "sort.h"
/**
 * quick_sort - sorts an array using quicksort(Lomuto Partition scheme)
 * @array: the array
 * @size: sizeof the array
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quickSort(array, 0, size - 1, size);
}
/**
 * Swap - swaps two elements in an array
 * @a: 1st element
 * @b: 2nd element
 * Return: nothing
 */

void Swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - partitions the array AR
 * @array: array
 * @low: first elemnt
 * @high: last
 * @size: array size
 * Return: pivot point
 */
int partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j = high + 1;
	int pivot;

	i = low - 1;
	pivot = array[low];
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
 * quickSort - helps sort integers in an array
 * @array: array
 * @low: start point
 * @high: last element
 * @size: array size
 * Return: nothing.
 */

void quickSort(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_i;

	if (low < high)
	{
		pivot_i = partition(array, low, high, size);
		quickSort(array, low, pivot_i, size);
		quickSort(array, pivot_i + 1, high, size);
	}
}
