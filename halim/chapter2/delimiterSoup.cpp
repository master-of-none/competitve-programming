//! Kattis - Delimiter Soup
//!
//! Submitted By: Shrikrishna Bhat

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char, char> hashmap = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };
    int n;
    cin >> n;
    stack<char> stack;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string input;
    getline(cin, input);

    int i = 0;
    char missed = '\0';
    bool error = false;
    for (char c : input) {
        if (c == ' ') {
            i++;
            continue;
        }
        if (hashmap.count(c)) {
            if (!stack.empty() && stack.top() == hashmap[c]) {
                stack.pop();
            } else {
                missed = c;
                error = true;
                break;
            }
        } else {
            stack.push(c);
        }
        i++;
    }

    if (!error) {
        cout << "ok so far\n";
    } else {
        cout << missed << " " << i << "\n";
    }
}