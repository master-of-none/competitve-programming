/* @JUDGE_ID: 1709779 13055 C++ "Inception" */

//!
//! Solved By: Shrikrishna Bhat
//!

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string command;
    stack<string> dreams;

    while (n--) {
        cin >> command;
        if (command == "Sleep") {
            string name;
            cin >> name;
            dreams.push(name);
        } else if (command == "Kick") {
            if (!dreams.empty()) dreams.pop();
        } else if (command == "Test") {
            if (dreams.empty())
                cout << "Not in a dream\n";
            else
                cout << dreams.top() << "\n";
        }
    }
    return 0;
}