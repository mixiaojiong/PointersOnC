#include <stdio.h>
#define QUEUE_TYPE int

void create_queue(size_t size);
void destroy_queue(void);
void queue_insert(QUEUE_TYPE value);
void queue_delete(void);
QUEUE_TYPE queue_first(void);
int queue_is_empty(void);
int queue_is_full(void);
