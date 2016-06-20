#include "singly_linked_list_node.h"
void create(Node *root) {
    Node *pPrev, *pCurr;
    int i = 0;
    pPrev = root;
    for(i = 0; i < 3; i++)
    {
        pCurr = (Node *)malloc(sizeof(Node));
        pCurr->value = i + 1;
        pCurr->link = NULL;
        pPrev->link = pCurr;
        pPrev = pCurr;
    }
}
int getListNodeNum(Node *root) {
    Node *p = root->link;
    int num = 0;
    while (p != NULL) {
        num++;
        p = p->link;
    }
    return num;
}
Node *find(Node *root, int x) {
    while(root != NULL) {
        if (root->value == x) {
            return root;
        }
        root = root->link;
    }
    return NULL;
}
Node *sll_reverse(Node *first) {
    if (first == NULL) {
        return NULL;
    }
    if (first->link == NULL) {
        return NULL;
    }
    Node *res = NULL;
    Node *tmp = NULL;
    while(first != NULL) {
        tmp = first;
        first = first->link;
        tmp->link = res;
        res = tmp;
    }
    return res;
}
void my_list(Node *first) {
    while (first != NULL) {
        printf("%d\n", first->value);
        first = first->link;
    }
}
int sll_remove(Node **head, Node *delete) {
    Node *current;
    while ((current = *head) != NULL && current != delete) {
        head = &current->link;
    }
    if (current == delete) {
        *head = current->link;
        free(current);
        return 1;
    }
    return 0;
}
void sll_traverse(Node *first, void(*func) (Node *node)) {
    first = first->link;
    while (first != NULL) {
        func(first);
        first = first->link;
    }
}
