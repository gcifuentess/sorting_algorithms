#include "sort.h"

void swap(listint_t *Node1, listint_t *Node2, listint_t **list);

/**
 * insertion_sort_list - sorts a linked list of integers in ascending order
 *                       using the Insertion sort algorithm
 * @list: the double linked list to be sorted
 *
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *back;
	int actual, next;

	if (!list || !*list || !((*list)->next))
		return;

	for (current = *list; current->next; current = current->next)
	{
		actual = current->n;
		next = current->next->n;
		if (actual > next)
		{
			swap(current, current->next, list);
			current = current->prev;
			for (back = current; back->prev; back = back->prev)
			{
				actual = back->n;
				next = back->prev->n;
				if (actual < next)
				{
					swap(back->prev, back, list);
					back = back->next;
				}
				else
					break;
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
