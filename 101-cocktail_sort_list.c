#include "sort.h"

void swap(listint_t *Node1, listint_t *Node2, listint_t **list);

/**
 * cocktail_sort_list - sorts a linked list of integers in ascending order
 *                      using the cocktail sort algorithm
 * @list: the double linked list to be sorted
 *
 * Return: Void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int swaped, actual, next;

	if (!list || !*list || !((*list)->next))
		return;

	swaped = 1;
	while (swaped)
	{
		swaped = 0;
		for (curr = *list; curr->next; curr = curr->next)
		{
			actual = curr->n;
			next = curr->next->n;
			if (actual > next)
			{
				swap(curr, curr->next, list);
				curr = curr->prev;
				swaped = 1;
			}
		}
		if (!swaped)
			break;
		swaped = 0;
		for (; curr->prev; curr = curr->prev)
		{
			actual = curr->n;
			next = curr->prev->n;
			if (actual < next)
			{
				swap(curr->prev, curr, list);
				curr = curr->next;
				swaped = 1;
			}
		}
	}
}

/**
 * swap - swap two nodes
 * @Node1: the node to swap with Node2
 * @Node2: the node to swap with Node1
 * @list: the double linked list
 *
 * Return: Void
 */
void swap(listint_t *Node1, listint_t *Node2, listint_t **list)
{
	listint_t *A, *B, *C, *D;

	A = Node1->prev;
	B = Node1;
	C = Node2;
	D = Node2->next;

	/* Initial A->B->C->D; Final A->C->B->D*/
	if (A)
		A->next = C;
	C->prev = A;
	C->next = B;
	B->prev = C;
	B->next = D;
	if (D)
		D->prev = B;

	if (*list == B)
		*list = C;

	print_list((const listint_t *)*list);
}
