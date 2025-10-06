#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        unordered_set<int> hashset;

        for (int i = 1; i < n; i++) {
            hashset.insert(i);
        }
        for (int i = 1; i < n; i++) {
            int temp = abs(nums[i - 1] - nums[i]);
            hashset.erase(temp);
        }

        if (hashset.empty()) {
            cout << "Jolly\n";
        } else {
            cout << "Not Jolly\n";
        }
    }
}