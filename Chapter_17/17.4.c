#include "stack_more.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define LEN 5
static STACK_TYPE *stack[LEN];
static size_t stack_size[5];
static int top_element[5] = {-1, -1, -1, -1, -1};
void list(void);

int main(void) {
    create_stack(2, 0);
    push(5, 0);
    push(6, 0);
    create_stack(2, 1);
    push(7, 1);
    push(8, 1);
    list();
}
void create_stack(size_t size, size_t index) {
    assert(stack_size[index] == 0);
    stack_size[index] = size;
    stack[index] = malloc(stack_size[index] * sizeof(STACK_TYPE));
    assert(stack[index] != NULL);
}
void destroy_stack(size_t index) {
    assert(stack_size > 0);
    stack_size[index] = 0;
    free(stack[index]);
}
void push(STACK_TYPE value, size_t index) {
    assert(!is_full(index));
    top_element[index]++;
    stack[index][top_element[index]] = value;
}
void pop(size_t index) {
    assert(!is_empty(index));
    top_element[index]--;
}
STACK_TYPE top(size_t index) {
    assert(!is_empty(index));
    return stack[index][top_element[index]];
}
int is_empty(size_t index) {
    assert(stack_size > 0);
    return top_element[index] == -1;
}
int is_full(size_t index) {
    assert(stack_size[index] > 0);
    return top_element[index] == stack_size[index] - 1;
}
void list(void) {
    int i, j;
    for (i = 0; i < LEN; i++) {
        if (top_element[i] == -1) {
            continue;
        }
        while(top_element[i] != -1) {
            printf("%d\t", top(i));
            pop(i);
        }
        printf("\n");
    }
}
