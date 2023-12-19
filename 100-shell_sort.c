#include "sort.h"
/**
 * shell_sort - sorts an array in ascending order using the shell sort
 * @array: array
 * @size: array size
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int temp;

	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
				array[j] = temp;
		}
		print_array(array, size);
		gap = gap / 3;
	}
}

