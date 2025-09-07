#include "header.h"
using namespace std;

int stock(vector<int> &nums) {
    int l = 0;
    int res = 0;

    for (int r = 0; r < nums.size(); r++) {
        if (nums[r] > nums[l]) {
            int profit = nums[r] - nums[l];
            res = max(profit, res);
        } else {
            l = r;
        }
    }
    return res;
}