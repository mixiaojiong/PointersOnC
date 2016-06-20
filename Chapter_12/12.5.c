#include "singly_linked_list_node.h"

int main (void) {
    Node *root;
    root = (Node *)malloc(sizeof(Node));
    create(root);
    printf("length is :%d\n", getListNodeNum(root));
    my_list(root);
    Node *delete;
    delete = find(root, 2);
    printf("remove is :%d\n", sll_remove(&root, delete));
    my_list(root);
}
