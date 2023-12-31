#include "sort.h"

/**
 * sSwap - swaps two array ints positions
 * @left: int at  sorted portion
 * @right: int at unsorted portion
 * Return: nothing
 */
void sSwap(int *left, int *right)
{
	int temp;

	temp = *left;
	*left = *right;
	*right = temp;
}
/**
 * partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				sSwap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		sSwap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * quik_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Return: nothing
 */
void quik_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition(array, size, left, right);
		quik_sort(array, size, left, part - 1);
		quik_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * quick_sort - Initiate the quicksort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: Uses the Lomuto partition scheme
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quik_sort(array, size, 0, size - 1);
}
