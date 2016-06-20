#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *link;
    int value;
}Node;

int getListNodeNum(Node *root);

int main (void) {
    Node *root;
    Node *new;
    new = (Node *)malloc(sizeof(Node));
    if (new == NULL) {
        printf("error");
    }
    new->value = 5;
    new->link = NULL;
    root->link = new;
    Node *new1;
    new1 = (Node *)malloc(sizeof(Node));
    if (new1 == NULL) {
        printf("error");
    }
    new1->value = 6;
    new1->link = NULL;
    root->link->link = new1;
    printf("%d", getListNodeNum(root));
}
int getListNodeNum(Node *root) {
    Node *p = root;
    int num = 0;
    while (p->link != NULL) {
        p = p->link;
        num++;
    }
    return num;
}

