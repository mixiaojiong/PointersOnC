#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static QUEUE_TYPE *queue;
static size_t front = 1;
static size_t rear = 0;
static size_t queue_size;

int main(void) {
}
void create_queue(size_t size) {
    assert(size == 0);
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
void insert(QUEUE_TYPE value){
    assert(!is_full());
    rear = (rear + 1) % queue_size;
    queue[rear] = value;
}
void delete(void) {
    assert(!is_empty());
    front = (front + 1) % queue_size;
}
QUEUE_TYPE first(void) {
    assert(!is_empty());
    return queue[front];
}
int is_empty(void) {
    return (rear + 1) % queue_size == front;
}
int is_full(void) {
    return (rear + 2) % queue_size == front;
}

void resize_queue(size_t new_size) {
    QUEUE_TYPE *old_queue;
    int i;
    int rear_plus_one;
    if (front <= rear) {
        i = rear - front + 1;
    } else {
        i = queue_size - front + rear + 1;
    }
    i %= queue_size;
    assert(new_size >= i);
    old_queue = queue;
    queue = malloc(new_size * sizeof(QUEUE_TYPE));
    assert(queue != NULL);
    queue_size = new_size;
    rear_plus_one = ( rear + 1 ) % queue_size;
    for (i = 0; front != rear_plus_one; i++) {
        queue[i] = old_queue[front];
        front = (front + 1) % queue_size;
    }
    front = 0;
    rear = (i + queue_size - 1) % queue_size;
    free(old_queue);
}
