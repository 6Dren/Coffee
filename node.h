#ifndef NODE
#define NODE

typedef struct node {
	int id;
	char *name;
	float price;
	struct node *next;
	struct node *prev;
} node_t;

void writeNode(node_t **head, node_t *item);

void clearNode(node_t **head);

void printNode(node_t *head);

#endif
