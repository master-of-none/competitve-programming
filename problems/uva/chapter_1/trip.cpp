/* @JUDGE_ID: 1709779 10137 C++ "Trip"*/

//!
//! Solved By: Shrikrishna Bhat
//!

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void calculateExchange(int n) {
    vector<int> expenses(n);
    int total = 0;

    for (int i = 0; i < n; i++) {
        double amount;
        cin >> amount;
        expenses[i] = round(amount * 100);
        total += expenses[i];
    }
    int average = total / n;
    int remainder = total % n;

    int res = 0;
    for (int i = 0; i < n; i++) {
        int target = average;
        if (expenses[i] > average && remainder > 0) {
            target++;
            remainder--;
        }
        if (expenses[i] > target) {
            res += expenses[i] - target;
        }
    }

    cout << fixed << setprecision(2);
    cout << "$" << (res / 100) << "." << setw(2) << setfill('0') << (res % 100)
         << endl;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        calculateExchange(n);
    }
    return 0;
}