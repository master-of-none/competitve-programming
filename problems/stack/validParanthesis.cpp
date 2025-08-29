#include "header.h"
using namespace std;
bool isValid(string s) {
    unordered_map<char, char> hashmap = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };
    stack<char> stack;

    for (char c : s) {
        if (hashmap.find(c) != hashmap.end()) {
            if (!stack.empty() and stack.top() == hashmap[c]) {
                stack.pop();
            } else {
                return false;
            }

        } else {
            stack.push(c);
        }
    }
    return stack.empty();
}