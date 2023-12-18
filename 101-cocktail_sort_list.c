
#include "sort.h"

/**
  * cocktail_sort_list - ...
  * @list: ...
  *
  * Return: ...
  */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL, *left = NULL, *right = NULL;
	int cycle_type = INCREMENT;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = *list;
	left = current;
	right = get_element(*list);

	while (left != right)
	{
		if (current->n == current->next->n)
			break;
		else if (current->n > current->next->n && cycle_type == INCREMENT)
			partition(list, current), print_list(*list);
		else if (current->next->n < current->n && cycle_type == DECREMENT)
			partition(list, current), current = current->prev, print_list(*list);
		else if (cycle_type == INCREMENT)
			current = current->next;
		else if (cycle_type == DECREMENT)
			current = current->prev;

		if (cycle_type == DECREMENT && current->next == left)
		{
			cycle_type = INCREMENT;
			current = current->next;
		}

		if (cycle_type == INCREMENT && current->prev == right)
		{
			right = right->prev;
			cycle_type = DECREMENT;
			current = current->prev;
		}
	}
}

/**
  * partition - ...
  * @list: ...
  * @node: ...
  *
  * Return: ...
  */
void partition(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;

	if (node->next->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}

/**
  * get_element - ...
  * @h: ...
  *
  * Return: ...
  */
listint_t *get_element(listint_t *h)
{
	listint_t *current = h;

	while (current->next != NULL)
		current = current->next;

	return (current);
}

