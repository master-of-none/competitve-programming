/* @JUDGE_ID: 1709779 00551 C++ "Bunch Of Brackets"*/
//!
//! Solved By: Shrikrishna Bhat
//!

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stack<char> st;

        int len = 0;
        bool bad = false;
        for (size_t i = 0; i < line.length(); i++) {
            len++;
            if (line[i] == '(') {
                if (i != line.length() - 1 && line[i + 1] == '*') {
                    st.push('*');
                    i++;
                } else {
                    st.push(')');
                }
            } else if (line[i] == '{') {
                st.push('}');
            } else if (line[i] == '[') {
                st.push(']');
            } else if (line[i] == '<') {
                st.push('>');
            } else if ((line[i] == '*' && i != line.length() - 1 &&
                        line[i + 1] == ')') ||
                       line[i] == '>' || line[i] == ')' || line[i] == ']' ||
                       line[i] == '}') {
                if (st.size() && st.top() == line[i]) {
                    st.pop();
                    if (line[i] == '*') i++;
                } else {
                    cout << "NO " << len << endl;
                    bad = true;
                    break;
                }
            }
        }

        if (bad) continue;

        if (!st.size()) {
            cout << "YES\n";
        } else {
            cout << "NO " << len + 1 << endl;
        }
    }

    return 0;
}