#include "header.h"
using namespace std;

int maxSubArray(vector<int>& nums) {
    int curSum = 0;
    int res = nums[0];

    for (auto n : nums) {
        if (curSum < 0) {
            curSum = 0;
        }

        curSum += n;
        res = max(res, curSum);
    }
    return res;
}