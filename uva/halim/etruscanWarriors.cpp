/* @JUDGE_ID: 1709779 11614 C++ "Etruscan Warriors"*/

//!
//! Solved By: Shrikrishna Bhat
//!

#include <math.h>

#include <iostream>

using namespace std;

long long computeRows(long long n) {
    //!  (k * (k+1) ) / 2 <= n
    //! k*k + k - 2n = 0
    //! k = |_ (-1 + sqrt(1 + 8 * n))/ 2 _|

    long double val = sqrt((long double)(1 + 8.0L * n));
    long long res = (long long)((-1 + val) / 2.0L);
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        long long n;
        cin >> n;
        long long res = computeRows(n);
        cout << res << "\n";
        t--;
    }
}
