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
TreeNode* Create();

int main(void) {
    tree = Create(tree);
    printf("=====\n");
    do_pre_order_traverse(tree);

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
        do_pre_order_traverse(current->right);
        printf("%d\n", current->value);
        free(current);
    }
}
