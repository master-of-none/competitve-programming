#include "header.h"
#include "treeNode.h"

using namespace std;

bool isBalanced(TreeNode *root) { return dfs(root).first; }

pair<bool, int> dfs(TreeNode *root) {
    if (not root) {
        return {true, 0};
    }
    pair<bool, int> left = dfs(root->left);
    pair<bool, int> right = dfs(root->right);

    bool balanced =
        left.first and right.first and abs(left.second - right.second) <= 1;

    int height = 1 + max(left.second, right.second);
    return {balanced, height};
}