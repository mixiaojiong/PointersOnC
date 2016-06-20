#include "tree_search.h"
#include "tree_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TREE_SIZE 100
#define ARRAY_SIZE (TREE_SIZE + 1)

static TREE_TYPE tree[ARRAY_SIZE];

void show(TREE_TYPE value);
void breadth_first_traversal(void(*callback)(TREE_TYPE value));
int main(void) {
    insert(20);
    insert(12);
    insert(25);
    insert(5);
    insert(16);
    insert(9);
    insert(17);
    insert(28);
    insert(26);
    insert(29);
    pre_order_traverse(show);
    printf("========\n");
    breadth_first_traversal(show);
}
void show(TREE_TYPE value) {
    printf("%d\n", value);
}

static int left_child(int current) {
    return current * 2;
}
static int right_child(int current) {
    return current * 2 + 1;
}
void insert(TREE_TYPE value) {
    int current;
    assert(value != 0);
    current = 1;
    while(tree[current] != 0) {
        if (value < tree[current]) {
            current = left_child(current);
        } else {
            assert(value != tree[current]);
            current = right_child(current);
        }
    }
    assert(current < ARRAY_SIZE);
    tree[current] = value;
}
TREE_TYPE *find(TREE_TYPE value) {
    int current;
    current = 1;
    while(current < ARRAY_SIZE && tree[current] != value) {
        if (value < tree[current]) {
            current = left_child(current);
        } else {
            current = right_child(current);
        }
    }
    if (current < ARRAY_SIZE) {
        return tree + current;
    }
    return 0;
}
static void do_pre_order_traverse(int current, void(*callback)(TREE_TYPE value)) {
    if (current < ARRAY_SIZE && tree[current] != 0) {
        callback(tree[current]);
        do_pre_order_traverse(left_child(current), callback);
        do_pre_order_traverse(right_child(current), callback);
    }
}
void pre_order_traverse(void(*callback)(TREE_TYPE value)) {
    do_pre_order_traverse(1, callback);
}
void breadth_first_traversal(void(*callback)(TREE_TYPE value)) {
    create_queue(20);
    int current;
    int child;
    queue_insert(1);
    while(!queue_is_empty()) {
        current = queue_first();
        queue_delete();
        callback(tree[current]);
        child = left_child(current);
        if (child < ARRAY_SIZE && tree[child] != 0) {
            queue_insert(child);
        }
        child = right_child(current);
        if (child < ARRAY_SIZE && tree[child] != 0) {
            queue_insert(child);
        }
    }
}
