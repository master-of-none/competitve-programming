#include "treeNode.h"
bool sameTree(TreeNode *, TreeNode *);

bool isSubtree(TreeNode *root, TreeNode *subroot) {
    if (not subroot) {
        return true;
    }
    if (not root) {
        return false;
    }
    if (sameTree(root, subroot)) {
        return true;
    }
    return isSubtree(root->left, subroot) or isSubtree(root->right, subroot);
}

bool sameTree(TreeNode *p, TreeNode *q) {
    if (not p and not q) {
        return true;
    }
    if (p and q and p->val == q->val) {
        return sameTree(p->left, q->left) and sameTree(p->right, q->right);
    }
    return false;
}