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

int do_pre_order_traverse(TreeNode *current, int *prev);
TreeNode* Create();

int main(void) {
    tree = Create(tree);
    int prev = INT_MIN;
    int res = do_pre_order_traverse(tree, &prev);
    printf("res is %d\n", res);

}
//先序拓展序列建立二叉树
TreeNode *Create(TreeNode *bTree)
{
	bTree = (TreeNode *)malloc(sizeof(TreeNode));
    scanf("%d", &bTree->value);            //按先序建立二叉树
    if(bTree->value != 0)
    {
		bTree->left = Create(bTree->left);
		bTree->right = Create(bTree->right);
    } else {
        bTree = NULL;    //置为NULL后结束
	}
    return bTree;
}
int do_pre_order_traverse(TreeNode *current, int *prev) {
    if (!current) return 1;
    if (do_pre_order_traverse(current->left, prev)) {
        if (current->value > *prev) {
            *prev = current->value;
            return do_pre_order_traverse(current->right, prev);
        } else {
            printf("%d\n", current->value);
            return 0;
        }
    } else {
        return 0;
    }
}
