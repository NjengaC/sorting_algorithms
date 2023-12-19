#include "sort.h"

/**
 * heap_tree - performs a sift-down operation to maintain the heap property
 * @array: array
 * @size: size of the array
 * @base: size of the heap
 * @root: index to start form
 */
void heap_tree(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		Swap(array + root, array + large);
		print_array(array, size);
		heap_tree(array, size, base, large);
	}
}

/**
 * heap_sort - sorts an array of integers using the Heap Sort algorithm
 * @array: array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (!array || size < 2)
		return;


	for (i = size / 2 - 1; i >= 0; i--)
		heap_tree(array, size, size, (size_t)i);


	for (i = size - 1; i > 0; i--)
	{

		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);


		heap_tree(array, size, i, 0);
	}
}
