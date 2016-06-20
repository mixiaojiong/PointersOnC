#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define TREE_TYPE int
typedef struct TREE_NODE {
    TREE_TYPE value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
}TreeNode;

static TreeNode *tree;

void do_pre_order_traverse(TreeNode *current);
void del(int value);
TreeNode* Create();
void insert(TREE_TYPE value);

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
    do_pre_order_traverse(tree);
    printf("=========\n");
    del(28);
    do_pre_order_traverse(tree);
    printf("=========\n");

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
//先序拓展序列建立二叉树
TreeNode *Create(TreeNode *bTree)
{
    int input;
    scanf("%d", &input);            //按先序建立二叉树
    if(input != 0)
    {
        bTree = (TreeNode *)malloc(sizeof(TreeNode));
        bTree->value = input;
		bTree->left = Create(bTree->left);
		bTree->right = Create(bTree->right);
    } else {
        bTree = NULL;    //置为NULL后结束
	}
    return bTree;
}
void do_pre_order_traverse(TreeNode *current) {
    if (current != NULL) {
        do_pre_order_traverse(current->left);
        printf("%d\n", current->value);
        do_pre_order_traverse(current->right);
        //free(current);
    }
}
void del(int value) {
    TreeNode **link;
    TreeNode *current;
    link = &tree;
    while ((current = *link) != NULL && value != current->value) {
        if (value < current->value) {
            link = &current->left;
        } else {
            link = &current->right;
        }
    }
    assert(current != NULL);
    if (current->left == NULL && current->right == NULL) {
        *link = NULL;
        free(current);
    } else if (current->left == NULL || current->right == NULL) {
        if (current->left == NULL) {
            *link = current->right;
        } else {
            *link = current->left;
        }
        free(current);
    } else {
        TreeNode *this;
        TreeNode *next;
        this = current->left;
        next = this->right;
        while(next != NULL) {
            this = next;
            next = this->right;
        }
        value = this->value;
        del(value);
        current->value = value;
    }
}
