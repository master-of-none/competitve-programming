/* @JUDGE_ID: 1709779 11988 C++ "Broken Keyboard" */

//!
//! Solved By: Shrikrishna Bhat
//!

#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        list<char> text;
        auto it = text.begin();

        for (char c : line) {
            if (c == '[') {
                it = text.begin();
            } else if (c == ']') {
                it = text.end();
            } else {
                text.insert(it, c);
            }
        }
        for (char c : text) {
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}