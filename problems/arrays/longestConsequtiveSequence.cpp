#include "header.h";
using namespace std;
int longest(vector<int> &nums) {
    unordered_set<int> hashset(nums.begin(), nums.end());
    int res = 0;

    for (int n : nums) {
        if (hashset.find(n - 1) == hashset.end()) {
            int length = 1;

            while (hashset.find(n + length) != hashset.end()) {
                length += 1;
            }
            res = max(res, length);
        }
    }
    return res;
}