#include "tree_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
static QUEUE_TYPE *queue;
static size_t front = 1;
static size_t rear = 0;
static size_t queue_size;

void create_queue(size_t size) {
    assert(size != 0);
    queue_size = size;
    queue = malloc(queue_size * sizeof(QUEUE_TYPE));
    assert(queue != NULL);
}
void destroy_queue(void) {
    assert(queue_size > 0);
    queue_size = 0;
    free(queue);
    queue = NULL;
}
void queue_insert(QUEUE_TYPE value){
    assert(!queue_is_full());
    rear = (rear + 1) % queue_size;
    queue[rear] = value;
}
void queue_delete(void) {
    assert(!queue_is_empty());
    front = (front + 1) % queue_size;
}
QUEUE_TYPE queue_first(void) {
    assert(!queue_is_empty());
    return queue[front];
}
int queue_is_empty(void) {
    return (rear + 1) % queue_size == front;
}
int queue_is_full(void) {
    return (rear + 2) % queue_size == front;
}

