#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
static STACK_TYPE *stack;
static size_t stack_size;
static int top_element = -1;

int main(void) {
    create_stack(2);
    push(5);
    push(6);
    resize_stack(5);
    push(8);
}
void create_stack(size_t size) {
    assert(stack_size == 0);
    stack_size = size;
    stack = malloc(stack_size * sizeof(STACK_TYPE));
    assert(stack != NULL);
}
void destroy_stack(void) {
    assert(stack_size > 0);
    stack_size = 0;
    free(stack);
}
void push(STACK_TYPE value) {
    assert(!is_full());
    top_element++;
    stack[top_element] = value;
}
void pop(void) {
    assert(!is_empty());
    top_element--;
}
STACK_TYPE top(void) {
    assert(!is_empty());
    return stack[top_element];
}
int is_empty(void) {
    assert(stack_size > 0);
    return top_element == -1;
}
int is_full(void) {
    assert(stack_size > 0);
    return top_element == stack_size - 1;
}
void resize_stack(size_t new_size) {
    STACK_TYPE *old_stack;
    int i;
    assert(new_size > top_element);
    old_stack = stack;
    stack = (STACK_TYPE *)malloc(new_size * sizeof(STACK_TYPE));
    assert(stack != NULL);
    stack_size = new_size;
    for (i = 0; i < top_element; i++) {
        stack[i] = old_stack[i];
    }
    free(old_stack);
}
