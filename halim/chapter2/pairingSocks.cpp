// Kattis Pairing Socks
//
//! Solved By: Shrikrishna Bhat

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> socks(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> socks[i];

    stack<int> mainPile, auxPile;

    for (int i = 2 * n - 1; i >= 0; i--) {
        mainPile.push(socks[i]);
    }

    int moves = 0;
    while (!mainPile.empty()) {
        if (!auxPile.empty() && auxPile.top() == mainPile.top()) {
            auxPile.pop();
            mainPile.pop();
            moves++;
        } else {
            auxPile.push(mainPile.top());
            mainPile.pop();
            moves++;
        }
    }
    if (auxPile.empty())
        cout << moves << "\n";
    else
        cout << "Impossible";
}