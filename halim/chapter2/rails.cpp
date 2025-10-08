/* @JUDGE_ID: 1709779 00514 C++ "Rails" */
//!
//! Solved By: Shrikrishna Bhat
//!

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        while (true) {
            vector<int> target(N);
            cin >> target[0];

            if (target[0] == 0) {
                cout << "\n";
                break;
            }

            for (int i = 1; i < N; i++) {
                cin >> target[i];
            }

            stack<int> stack;
            int next = 1;
            int i = 0;

            while (next <= N || !stack.empty()) {
                if (!stack.empty() && stack.top() == target[i]) {
                    stack.pop();
                    i++;
                } else if (next <= N) {
                    stack.push(next);
                    next++;
                } else {
                    break;
                }
            }

            if (i == N)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}