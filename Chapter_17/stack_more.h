#include <stdio.h>
#define STACK_TYPE int

void push(STACK_TYPE value, size_t index);
void pop(size_t index);
STACK_TYPE top(size_t index);
int is_empty(size_t index);
int is_full(size_t index);
void create_stack(size_t size, size_t index);
void destroy_stack(size_t index);
