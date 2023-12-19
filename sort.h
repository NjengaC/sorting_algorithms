#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *large, int *small);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void sswap(int *left, int *right);
void quickSort(int *array, size_t low, size_t high, size_t size);
int partition(int *array, int low, int high, size_t size);
void Swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void insert(int *array, size_t size);
void cocktail_sort_list(listint_t **Head);
void list_swap(listint_t **node, listint_t **head);
void shellsort(int *array, size_t size);
void counting_sort(int *array, size_t size);

#endif
