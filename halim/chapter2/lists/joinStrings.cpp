//! Kattis - Join Strings
//!
//! Submitted By: Shrikrishna Bhat
//!

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    vector<int> next(n, -1);
    vector<int> tail(n);  // tail[i] = the last node in i's chain
    for (int i = 0; i < n; i++) {
        tail[i] = i;  // initially, each string is its own tail
    }

    int last = 0;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--;
        b--;
        next[tail[a]] = b;  // attach b to the tail of a's chain
        tail[a] = tail[b];  // update a's tail to b's tail
        last = a;
    }

    // Follow the chain starting from 'last'
    for (int i = last; i != -1; i = next[i]) {
        cout << input[i];
    }
    cout << "\n";
}