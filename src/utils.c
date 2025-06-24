#include "utils.h"

Node* init_node(const char *const cmd, const Node *const n) {
    Node *const node = malloc(sizeof(Node));
    node->command = cmd;
    node->next = n;
    return node;
}