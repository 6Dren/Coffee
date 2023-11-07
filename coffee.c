#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <sysexits.h>
#include "node.h"
#include "file.h"

void clearScreen()
{
	system("clear");
}

void addItem(node_t **head, FILE *fptr)
{
	clearScreen();

	node_t *item;
	item = (node_t *)(malloc(sizeof(node_t)));

	printf("type the id: ");
	scanf("%d", &(item->id));
	getchar();

	printf("type the name: ");
	item->name = calloc(30, sizeof(char));
	fgets(item->name, 30, stdin);
	item->name[strlen(item->name) - 1] = '\0';

	printf("type the price: ");
	scanf("%f", &(item->price));
	getchar();

	writeNode(head, item);

	writeFile(fptr, item);
}

int main()
{
	node_t *head = (node_t *)(NULL);
	FILE *fptr;

	fptr = fopen("menu.bin", "ab+");

	int i = 1;
	while (i != 0)
	{
		clearScreen();

		i = 1;
		printf("Type [ 1 ] : Add item\nType [ 2 ] : Show menu\nType [ 3 ] : Clear Menu\nType [ 0 ] : Exit\n-> ");
		scanf("%d", &i);
		getchar();
		switch (i)
		{
		case 1:
			addItem(&head, fptr);
			// writeFile(fptr, head);
			break;
		case 2:
			readFile(fptr, &head);
			printNode(head);
			printf("\nPress enter to continue >> ");
			getchar();
			break;
		case 3:
			clearFile(&head);
			break;
		case 0:
			i = 0;
			break;
		}
	}
	fclose(fptr);
}
