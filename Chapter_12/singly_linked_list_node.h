#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    struct Node *link;
    int value;
}Node;
void my_list(Node *first);
void create(Node *root);
int getListNodeNum(Node *root);
Node *find(Node *root, int x);
Node *sll_reverse(Node *first);
int sll_remove(Node **head, Node *delete);
