#include "singly_linked_list_node.h"
void my_print(Node *node) {
    printf("%d====\n", node->value);
}
int main (void) {
    Node *root;
    root = (Node *)malloc(sizeof(Node));
    create(root);
    printf("length is :%d\n", getListNodeNum(root));
    sll_traverse(root, my_print);
}
