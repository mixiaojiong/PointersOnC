#include "singly_linked_list_node.h"

int main (void) {
    Node *root;
    root = (Node *)malloc(sizeof(Node));
    create(root);
    printf("length is :%d\n", getListNodeNum(root));
    my_list(root);
    root = sll_reverse(root);
    my_list(root);
}
