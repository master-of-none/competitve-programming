//! Kattis - Sim
//!
//! Submitted by: Shrikrishna Bhat
//!

#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    /*
     //? * The below code will work only for 16 test cases and not for last 2
    edge cases that is for large inputs.

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);

        deque<char> left, right;

        for (char c : s) {
            if (c == '<') {
                if (!left.empty()) left.pop_back();
            } else if (c == '[') {
                while (!left.empty()) {
                    right.push_front(left.back());
                    left.pop_back();
                }
            } else if (c == ']') {
                while (!right.empty()) {
                    left.push_back(right.front());
                    right.pop_front();
                }
            } else
                left.push_back(c);
        }
        for (char c : left) cout << c;
        for (char c : right) cout << c;
        cout << "\n";
    }
    return 0;

    */

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);

        list<char> text;
        auto cursor = text.begin();

        for (char c : s) {
            if (c == '<') {
                if (cursor != text.begin()) {
                    cursor = prev(cursor);
                    cursor = text.erase(cursor);
                }
            } else if (c == '[')
                cursor = text.begin();
            else if (c == ']')
                cursor = text.end();
            else {
                cursor = text.insert(cursor, c);
                cursor++;
            }
        }

        for (char c : text) cout << c;
        cout << '\n';
    }
}