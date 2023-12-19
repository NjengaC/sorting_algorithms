#include "sort.h"
/**
 * radix_sort - sorts an array using radix sort
 * @array: array
 * @size: size
 * Return: nothing
 */

void radix_sort(int *array, size_t size)
{
	size_t i, pos;
	int max = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];

	}
	for (pos = 1; max / pos > 0; pos *= 10)
	{
		countsort(array, size, pos);
		print_array(array, size);
	}
}
/**
 * countsort - sorts using the standard counting sort
 * @array: array
 * @size: size of array
 * @pos: current position
 * Return: nothing
 */

void countsort(int *array, size_t size, int pos)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;
	int *temp, j;

	temp = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
	{
		++count[(array[i] / pos) % 10];
	}
	for (i = 1; i <= 9; i++)
	{
		count[i] = count[i] + count[i - 1];
	}
	for (j = (int)size - 1; j >= 0; j--)
	{
		temp[count[(array[j] / pos) % 10] - 1] = array[j];
		count[(array[j] / pos) % 10] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);
}
