#include "../header.h"
using namespace std;

vector<int> twoSumSorted(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
        int temp = nums[l] + nums[r];
        if (temp < target) {
            l++;
        } else if (temp > target) {
            r--;
        } else {
            return vector<int>{l + 1, r + 1};
        }
    }
    return vector<int>{};
}