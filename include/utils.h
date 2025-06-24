#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

typedef struct Node {
    const char* command;
    const struct Node* next;
} Node;

Node* init_node(const char *const cmd, const Node *const n);

#endif