#include <stdio.h>
#include <stdlib.h>
typedef struct NODE {
    struct NODE *fwd;
    struct NODE *bwd;
    int value;
}Node;

void create(Node *root) {
    Node *pPrev, *pCurr;
    int i = 0;
    pPrev = root;
    for(i = 0; i < 3; i++)
    {
        pCurr = (Node *)malloc(sizeof(Node));
        pCurr->value = i + 1;
        pCurr->fwd = NULL;
        pCurr->bwd = pPrev;
        pPrev->fwd = pCurr;
        pPrev = pCurr;
    }
}

int dll_remove(struct NODE *rootp, struct NODE *node) {
    while(rootp != NULL && rootp != node) {
        rootp = rootp->fwd;
    }
    if (rootp == node) {
        rootp->bwd->fwd = rootp->fwd;
        rootp->fwd->bwd = rootp->bwd;
        free(rootp);
        return 1;
    }
    return 0;
}

void my_list(Node *first) {
    while (first != NULL) {
        printf("%d\n", first->value);
        first = first->fwd;
    }
}
Node *find(Node *root, int x) {
    while(root != NULL) {
        if (root->value == x) {
            return root;
        }
        root = root->fwd;
    }
    return NULL;
}
int main (void) {
    Node *root;
    root = (Node *)malloc(sizeof(Node));
    root->value = -1;
    create(root);
    my_list(root);
    Node *node;
    node = find(root, 2);
    printf("remove is %d\n", dll_remove(root, node));
    my_list(root);
}
