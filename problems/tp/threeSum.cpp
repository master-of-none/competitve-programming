#include "./header.h"
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < (int)nums.size(); i++) {
        if (i > 0 and nums[i] == nums[i - 1]) {
            continue;
        }
        int l = i + 1;
        int r = nums.size() - 1;

        while (l < r) {
            int temp = nums[i] + nums[r] + nums[l];
            if (temp < 0) {
                l++;
            } else if (temp > 0) {
                r--;
            } else {
                res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                l++;
                r--;

                while (l < r and nums[l] == nums[l - 1]) {
                    l++;
                }
            }
        }
    }
    return res;
}