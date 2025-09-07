#include "header.h"
#include "treeNode.h"
using namespace std;

bool isValidBST(TreeNode* root) { return dfs(root, LONG_MIN, LONG_MAX); }

bool dfs(TreeNode* root, long left, long right) {
    if (not root) {
        return true;
    }
    if (not(left < root->val && root->val < right)) {
        return false;
    }
    return dfs(root->left, left, root->val) and
           dfs(root->right, root->val, right);
}
