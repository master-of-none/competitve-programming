#include "header.h"
#include "treeNode.h"

using namespace std;

int *maxDepth(TreeNode *root) {
    if (not root) {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}