#include "sort.h"
/**
 * list_swap - swaps a node and node next of a linked list
 * @node: node toswap
 * @head: head of list
 * Return: nothing
 */
void list_swap(listint_t **node, listint_t **head)
{
	listint_t *tmp, *tmp2, *tmp3;

	if (!(*node)->prev)
		*head = (*node)->next;


	tmp = *node;
	tmp2 = tmp->next;
	tmp3 = tmp->prev;

	tmp->next = tmp2->next;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	tmp2->prev = tmp3;

	if (tmp2->prev)
		tmp2->prev->next = tmp2;

	if (tmp->next)
		tmp->next->prev = tmp;

	*node = tmp2;
}

/**
 * cocktail_sort_list - sorts a DLL using corctail sort
 * @Head: Head of the linked list
 * Return: nothing
 */

void cocktail_sort_list(listint_t **Head)
{
	int start, end, traverser;
	listint_t *head, *copy, *new;

	if (!Head || !(*Head) || !(*Head)->next)
		return;

	head = new = *Head, start = end = 0, traverser = 1;
	while (true)
	{
		start++;
		while (head->next && traverser != end)
		{
			if (head->n > head->next->n)
			{
				copy = head, dll_swap(&copy, Head);
				head = copy, print_list(*Head);
			}
			traverser++;
			head = head->next;
		}

		if (start == 1)
			end = traverser;
		end--;

		while (head->prev && traverser >= start)
		{
			if (head->prev->n > head->n)
			{
				copy = head->prev, dll_swap(&copy, Head);
				head = copy->next, print_list(*Head);
			}
			traverser--;
			head = head->prev;
		}
		if (start > end)
			break;
	}
}
