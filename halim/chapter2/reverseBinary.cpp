//! Kattis - Reverse Binary
//! Submitted By: Shrikrishna Bhat

#include <iostream>
using namespace std;

int main() {
    long long n, res = 0;
    cin >> n;

    while (n) {
        res = (res << 1) | (n & 1);
        n >>= 1;
    }
    cout << res << "\n";
}