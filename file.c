#include "node.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>

void writeFile(FILE *fptr, node_t *item)
{
	rewind(fptr);

	fwrite(&item->id, sizeof(int), 1, fptr);
	fwrite(item->name, sizeof(char), 30, fptr);
	fwrite(&item->price, sizeof(float), 1, fptr);

}

void readFile(FILE *fptr, node_t **head)
{
	rewind(fptr);

	node_t *node1;
	node_t *node2;

	*head = NULL;

	do
	{
		if (fptr == NULL)
		{
			printf("Error!");
			exit(1);
		}

		node1 = (node_t *)(malloc(sizeof(node_t)));

		node1->name = (char *)(calloc(sizeof(char), 30));

		fread(&node1->id, sizeof(int), 1, fptr);
		fread(node1->name, sizeof(char), 30, fptr);
		fread(&node1->price, sizeof(float), 1, fptr);

		node1->next = (node_t *)(NULL);
		node1->prev = (node_t *)(NULL);

		if ((*node1->name))
		{
			// in first time
			if (!(*head))
			{
				*head = node2 = node1;
			}
			else
			{
				node2->next = node1;
				node1->prev = node2;

				node2 = node1;
			}
		}
	} while (!feof(fptr));
}

void clearFile(node_t **head)
{
	*head = NULL;
	//clearNode(head);
	fclose(fopen("menu.bin", "w"));
}

