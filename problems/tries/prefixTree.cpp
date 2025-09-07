#include "header.h"
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
    bool eow;

    TrieNode() { eow = false; }
};

class Trie {
public:
    TrieNode *root;

    Trie() { root = new TrieNode(); }

    void insert(const string &word) {
        TrieNode *cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->eow = true;
    }
    bool search(const string &word) {
        TrieNode *cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) return false;
            cur = cur->children[c];
        }
        return cur->eow;
    }
    bool startsWith(const string &prefix) {
        TrieNode *cur = root;
        for (char c : prefix) {
            if (cur->children.find(c) == cur->children.end()) return false;

            cur = cur->children[c];
        }
        return true;
    }
};