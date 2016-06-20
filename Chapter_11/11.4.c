#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *create(int value);

int main(void) {
    Node *head;
    head = create(5);
    head->next = create(10);
    head->next->next = create(15);
    head->next->next->next = create(0);
    EXIT_SUCCESS;
}

Node *create(int value) {
    Node *new;
    new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = value;
    return new;
}
