/* @JUDGE_ID: 1709779 12667 C++ "Median*/

//!
//! Solved By: Shrikrishna Bhat
//!

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;
    int x;

    while (cin >> x) {
        nums.push_back(x);
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int median;

        if (n % 2) {
            median = nums[n / 2];
        } else {
            median = (nums[n / 2] + nums[(n / 2) - 1]) / 2;
        }

        cout << median << "\n";
    }
}