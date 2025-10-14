//! Kattis Grand Adventurer
//!
//! Submitted By: Shrikrishna Bhat
//!

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string adventure;
        cin >> adventure;
        vector<char> stack;
        bool valid = true;

        for (char c : adventure) {
            if (c == '.') continue;
            if (c == '$' || c == '|' || c == '*')
                stack.push_back(c);
            else if (c == 'b') {
                if (stack.empty() || stack.back() != '$') {
                    valid = false;
                    break;
                } else
                    stack.pop_back();
            } else if (c == 't') {
                if (stack.empty() || stack.back() != '|') {
                    valid = false;
                    break;
                } else
                    stack.pop_back();
            } else if (c == 'j') {
                if (stack.empty() || stack.back() != '*') {
                    valid = false;
                    break;
                } else {
                    stack.pop_back();
                }
            }
        }
        if (!stack.empty()) valid = false;
        cout << (valid ? "Yes" : "No") << "\n";
    }
}