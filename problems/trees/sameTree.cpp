#include "header.h"
#include "treeNode.h"

using namespace std;

bool sameTree(TreeNode *p, TreeNode *q) {
    if (not p and not q) {
        return true;
    }
    if (p and q and p->val == q->val) {
        return sameTree(p->left, q->left) and sameTree(p->right, q->right);
    }

    return false;
}