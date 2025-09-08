#include "header.h"
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> hashmap;

    function<Node*(Node*)> dfs = [&](Node* node) -> Node* {
        if (hashmap.find(node) != hashmap.end()) {
            return hashmap[node];
        }
        Node* copy = new Node(node->val);
        hashmap[node] = copy;

        for (auto& n : node->neighbors) {
            copy->neighbors.push_back(dfs(n));
        }
        return copy;
    };
    return node ? dfs(node) : NULL;
}