#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 *  * main - Entry point
 *   *
 *    * Return: Always 0
 *     */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);
/*	int arr[100];
	int i, nn;*/

	print_array(array, n);
	printf("\n");
	insert(array, n);
	printf("\n");
	print_array(array, n);
	printf("\n");
/*
	srand(time(NULL));
	for (i = 0; i < 100; i++)
	{
		arr[i] = rand() % 1001;
	}
	nn = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, nn);

	selection_sort(arr, nn);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	print_array(arr, nn);
*/
	return (0);

}
