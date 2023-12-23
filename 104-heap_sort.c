#include "sort.h"

/**
 * heap_tree - performs a sift-down operation in order to maintain the heap
 * property
 * @array: array
 * @n: size of the array
 * @size: size of the heap
 * @index: index to start form
 */
void heap_tree(int *array, size_t n, size_t size, size_t index)
{
	size_t s1, s2;
	int val1, val2, tmp;

	s1 = 2 * index + 1;
	s2 = 2 * index + 2;
	val1 = (s1 < size) ? array[s1] : INT_MIN;
	val2 = (s2 < size) ? array[s2] : INT_MIN;

	if (val1 > val2 && val1 > array[index])
	{
		tmp = array[index];
		array[index] = array[s1];
		array[s1] = tmp;
		print_array(array, n);
		heap_tree(array, n, size, s1);
	}
	else if (val2 > val1 && val2 > array[index])
	{
		tmp = array[index];
		array[index] = array[s2];
		array[s2] = tmp;
		print_array(array, n);
		heap_tree(array, n, size, s2);
	}
}

/**
 * heap_sort - sorts an array of integers using the Heap Sort algorithm
 * @array: the array
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
