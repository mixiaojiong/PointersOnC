#include <stdio.h>
#include <stdlib.h>

void *my_calloc(size_t num_elements, size_t element_size);

int main(void) {
    char *x = my_calloc(10, sizeof(char));
    EXIT_SUCCESS;
}
void *my_calloc(size_t num_elements, size_t element_size) {
    char *ptr = malloc(num_elements * element_size);
    if (ptr != NULL) {
        char *tmp = ptr;
        for (int i = 0; i < num_elements; i++) {
            tmp[i] = '\0';
        }
    }
    return ptr;
}
