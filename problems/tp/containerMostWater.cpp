#include "./header.h"
using namespace std;

int mostWater(vector<int> &height) {
    int l = 0;
    int r = height.size() - 1;
    int res = 0;
    while (l < r) {
        int area = (r - l) * min(height[r], height[l]);
        res = max(area, res);

        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }
    return res;
}