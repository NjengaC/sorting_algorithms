#include "sort.h"
void insert(int *array, size_t size)
{
	size_t i, j, m;

	for (i = 0; i < size; i++)
	{
		j = i + 1;
		m = i;
		while (array[m] > array[j] && j != 0)
		{
			Swap(&array[m], &array[j]);
			j--;
			m--;
			print_array(array, size);
		}
	}
}
