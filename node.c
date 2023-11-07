#include "node.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>

void writeNode(node_t **head, node_t *item)
{
	node_t *node1;
	node_t *node2;

	node1 = (node_t *)(malloc(sizeof(node_t)));

	node1->next = (node_t *)(NULL);
	node1->prev = (node_t *)(NULL);

	item->next = NULL;
	item->prev = NULL;

	// in first time
	if (!(*head))
	{
		// use input
		node1 = item;

		*head = node2 = node1;
	}
	else
	{
		node1 = *head;
		while (node1->next != NULL /*node1->name != NULL*/)
			node1 = node1->next;
		item->prev = node1;
		node1->next = item;
	}
}


void clearNode(node_t **head)
{
	if (*head)
	{
		node_t *end;
		end = *head;
		while (end->next != NULL)
		{
			end = (*head)->next;
		}

		while (end != NULL)
		{
			free(end->name);
			if (end->next)
				free(end->next->prev);

			free(end->next);

			end = end->prev;
		}
	}
}

void printNode(node_t *head)
{
	node_t *node1;
	node1 = head;

	while (node1 != NULL)
	{
		printf("ID: %d | Name: %s | Price: $ %.2f\n", node1->id, node1->name, node1->price);
		node1 = node1->next;
	}
}

