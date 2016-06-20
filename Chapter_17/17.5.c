#include "tree_search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct TREE_NODE {
    TREE_TYPE value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
}TreeNode;

static TreeNode *tree;
void show(TREE_TYPE value);
int getNodeNum(TreeNode *root);

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
    printf("%d", getNodeNum(tree));

}

void show(TREE_TYPE value) {
    printf("%d\n", value);
}

void insert(TREE_TYPE value) {
    TreeNode *current;
    TreeNode **link;
    link = &tree;
    while((current = *link) != NULL) {
        if (value < current->value) {
            link = &current->left;
        } else {
            assert(value != current->value);
            link = &current->right;
        }
    }
    current = malloc(sizeof(TreeNode));
    assert(current != NULL);
    current->value = value;
    current->left = NULL;
    current->right = NULL;
    *link = current;
}
TREE_TYPE *find(TREE_TYPE value) {
    TreeNode *current;
    current = tree;
    while(current != NULL && current->value != value) {
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current != NULL) {
        return &current->value;
    }
    return NULL;
}
static void do_pre_order_traverse(TreeNode *current, void(*callback) (TREE_TYPE value)) {
    if (current != NULL) {
        callback(current->value);
        do_pre_order_traverse(current->left, callback);
        do_pre_order_traverse(current->right, callback);
    }
}
void pre_order_traverse(void(*callback)(TREE_TYPE value)) {
    do_pre_order_traverse(tree, callback);
}
int getNodeNum(TreeNode *root) {
    if(root == NULL) {
        return 0;
    }
    return getNodeNum(root->left) + getNodeNum(root->right) + 1;
}
