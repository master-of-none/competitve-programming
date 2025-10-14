//! Kattis - Circuit Math
//!
//! Submitted By: Shrikrishna Bhat

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int> freq(26, 0);
    int i = 0;
    while (n--) {
        char c;
        cin >> c;
        if (c == 'T') {
            freq[i] = 1;
        }
        i++;
    }

    // for (size_t i = 0; i < freq.size(); i++) {
    // cout << freq[i] << " ";
    // }

    char c;
    stack<bool> stack;
    while (cin >> c) {
        if (c == '*') {
            if (!stack.empty()) {
                bool v1 = stack.top();
                stack.pop();
                bool v2 = stack.top();
                stack.pop();

                stack.push(v1 & v2);
            }
        } else if (c == '+') {
            bool v1 = stack.top();
            stack.pop();
            bool v2 = stack.top();
            stack.pop();
            stack.push(v1 | v2);
        } else if (c == '-') {
            bool v1 = stack.top();
            stack.pop();
            stack.push(!v1);
        } else {
            stack.push(freq[int(c) - int('A')]);
        }
    }
    !stack.top() ? cout << "F\n" : cout << "T\n";
    return 0;
}