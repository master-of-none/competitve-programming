//! Kattis - Integer List
//!
//! Submitted By: Shrikrishna Bhat
//!

#include <deque>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string program;
        cin >> program;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        deque<int> q;
        if (arr != "[]") {
            int num = 0;
            bool reading = false;
            for (char c : arr) {
                if (isdigit(c)) {
                    num = num * 10 + (c - '0');
                    reading = true;
                } else if (reading) {
                    q.push_back(num);
                    num = 0;
                    reading = false;
                }
            }
        }

        cin.ignore();
        int flag = false;
        bool reversed = false;
        for (char c : program) {
            if (c == 'R') {
                reversed = !reversed;
            }
            if (c == 'D') {
                if (q.empty()) {
                    cout << "error\n";
                    flag = true;
                    break;
                }
                if (reversed) {
                    q.pop_back();
                } else {
                    q.pop_front();
                }
            }
        }
        stack<int> s;
        if (reversed) {
            while (!q.empty()) {
                s.push(q.front());
                q.pop_front();
            }
        }
        if (flag) continue;
        cout << "[";
        if (reversed) {
            bool first = true;
            while (!s.empty()) {
                if (!first) cout << ",";
                cout << s.top();
                s.pop();
                first = false;
            }
        } else {
            bool first = true;
            while (!q.empty()) {
                if (!first) cout << ",";
                cout << q.front();
                q.pop_front();
                first = false;
            }
        }
        cout << "]\n";
    }
}