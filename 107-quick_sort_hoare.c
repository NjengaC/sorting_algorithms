#include "sort.h"
/**
 * _partition - partitions using Hoare's scheme
 * @array: array
 * @low: low end index
 * @high: high end index
 * @size: size of the array
 * Return: index of the pivot
 */
int _partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int left = low - 1;
	int right = high + 1, temp;

	while (1)
	{
		do {
			left++;
		} while (array[left] < pivot);
		do {
			right--;
		} while (array[right] > pivot);
		if (left >= right)
			return (left);
		if (left != right)
		{
			temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			print_array(array, size);
		}
	}
}

/**
 * _quick_sort - quicksort
 * @array: array
 * @low: low
 * @high: high
 * @size: size of the array
 */
void _quick_sort(int *array, int low, int high, int size)
{
	int pivot;

	if (low < high)
	{
		pivot = _partition(array, low, high, size);
		_quick_sort(array, low, pivot - 1, size);
		_quick_sort(array, pivot, high, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_quick_sort(array, 0, size - 1, size);
}
