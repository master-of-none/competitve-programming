#include "treeNode.h"

TreeNode *invertTree(TreeNode *root) {
    if (not root) {
        return nullptr;
    }
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}