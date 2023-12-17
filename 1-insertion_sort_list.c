#include "sort.h"
/**
 * insertion_sort_list - sorts a ddl of ints in ascending ordr
 * @list: the list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	if (!list || (*list)->next == NULL || !*list)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
			{
				temp->prev->next = temp->next;
				if (temp->next != NULL)
					temp->next->prev = temp->prev;
				temp->next = temp->prev;
				temp->prev = temp->prev->prev;
				temp->next->prev = temp;

				if (temp->prev == NULL)
					*list = temp;
				else
					temp->prev->next = temp;
				print_list(*list);
			}
		current = current->next;
	}
}
