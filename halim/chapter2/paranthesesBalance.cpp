/* @JUDGE_ID: 1709779 00673 C++ "Balance"*/

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        stack<char> stack;
        unordered_map<char, char> hashmap = {
            {')', '('},
            {']', '['},
        };
        string s;
        getline(cin, s);
        bool valid = true;
        for (char c : s) {
            if (hashmap.count(c)) {
                if (!stack.empty() && stack.top() == hashmap[c]) {
                    stack.pop();
                } else {
                    valid = false;
                    break;
                }
            } else {
                stack.push(c);
            }
        }
        if (valid && stack.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}