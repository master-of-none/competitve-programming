/* @JUDGE_ID: 1709779 100 C++ "ThreeN+1"*/

//!
//! Solved By: Shrikrishna Bhat
//!

#include <iostream>
#include <vector>

using namespace std;

int cycle_length(int n) {
    // vector<int> array;
    int i = 1;
    while (n != 1) {
        int new_n = n;
        if (new_n % 2 == 0) {
            new_n = n / 2;
        } else {
            new_n = (new_n * 3) + 1;
        }
        i++;
        n = new_n;
    }
    return i;
}

int main() {
    int m, n;
    int maxVal;
    while (cin >> m >> n) {
        maxVal = 0;
        for (int i = min(m, n); i <= max(m, n); i++) {
            maxVal = max(maxVal, cycle_length(i));
        }
        cout << m << " " << n << " " << maxVal << endl;
    }

    return 0;
}