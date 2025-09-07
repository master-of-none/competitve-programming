#include "header.h"
#include "treeNode.h"
using namespace std;

vector<int> rightSideView(TreeNode *root) {
    vector<int> res;

    if (not root) {
        return res;
    }
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        TreeNode *rightNode;
        for (int i = 0; i < n; i++) {
            TreeNode *node = q.front();
            q.pop();

            if (node) {
                rightNode = node;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        if (rightNode) {
            res.push_back(rightNode->val);
        }
    }
    return res;
}