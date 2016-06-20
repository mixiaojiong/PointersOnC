#include "singly_linked_list_node.h"

int main (void) {
    Node *root;
    root = create();
    printf("length is :%d\n", getListNodeNum(root));
    Node *tmp;
    tmp = find(root, 5);
    printf("find value is %d\n", tmp->value);
}
