#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Node{
    QUEUE_TYPE value;
    struct Node *next;
}Node;
static size_t queue_size = 5;
static Node *front;
static Node *rear;

void list(void);

int main(void) {
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    insert(45);
    list();
}

void destroy_queue(void) {
    while(!is_empty()) {
        delete();
    }
}
void insert(QUEUE_TYPE value) {
    assert(queue_size != 0);
    queue_size--;
    Node *new_node;
    new_node = (Node *)malloc(sizeof(Node));
    assert(new_node != NULL);
    new_node->value = value;
    new_node->next = NULL;
    if (rear == NULL) {
        front = new_node;
    } else {
        rear->next = new_node;
    }
    rear = new_node;
}
void delete(void) {
    assert(queue_size != 5);
    queue_size++;
    Node * next_node;
    assert(!is_empty());
    next_node = front->next;
    free(front);
    front = next_node;
    if (front == NULL) {
        rear = NULL;
    }
}
QUEUE_TYPE first(void) {
    assert(!is_empty());
    return front->value;
}
int is_empty(void) {
    return front == NULL;
}
int is_full(void) {
    return queue_size == 0;
}
void list(void) {
    assert(!is_empty());
    Node *head;
    head = front;
    while(head != NULL) {
        printf("%d\n", head->value);
        head = head->next;
    }
}
