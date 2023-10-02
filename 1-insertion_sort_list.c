#include "sort.h"

/**
 * insertion_sort_list - Sorts a double linked list using
 * insertion sorting algorithm
 * @list: Doubly linked list of integers to be sorted.
 * Return: Void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t  *sorted_head, *current, *previous, *swap_previous, *swap_current;
	/* Check if list is sorted(single element) or list is empty */
	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	previous = *list;
	current = (*list)->next;
	sorted_head = *list;

	while (current)
	{
		swap_current = current;
		swap_previous = previous;
		while (swap_previous && swap_previous->n > swap_current->n)
		{
			/*Update head if it is to be swapped*/
			if (swap_previous->prev == NULL)
				sorted_head = swap_current;
			/*set current to point to the node that replaces current*/
			if (swap_current == current)
				current = swap_previous;
			/*perform Swap*/
			if (swap_current->next != NULL)
				swap_current->next->prev = swap_previous;

			if (swap_previous->prev != NULL)
				swap_previous->prev->next = swap_current;

			swap_current->prev = swap_previous->prev;
			swap_previous->next = swap_current->next;
			swap_current->next = swap_previous;
			swap_previous->prev = swap_current;

			swap_previous = swap_current->prev;
			print_list(sorted_head);
		}
		previous = current;
		current = current->next;
	}
	*list = sorted_head;
}
