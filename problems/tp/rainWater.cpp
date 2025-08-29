#include "header.h"
using namespace std;

int trap(vector<int> &height) {
    int l = 0, r = height.size() - 1, leftMax = height[l], rightMax = height[r],
        res = 0;

    while (l < r) {
        if (height[l] < height[r]) {
            leftMax = max(height[l], leftMax);
            res += leftMax - height[l];
            l++;
        } else {
            rightMax = max(height[r], rightMax);
            res += rightMax - height[r];
            r--;
        }
    }
    return res;
}