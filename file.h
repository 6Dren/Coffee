#ifndef FILES
#define FILES

#include "node.h"
#include <stdlib.h>
#include <stdio.h>

void writeFile(FILE *fptr, node_t *item);

void readFile(FILE *fptr, node_t **head);

void clearFile(node_t **head);

#endif
