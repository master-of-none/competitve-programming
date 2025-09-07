#include "header.h"
using namespace std;
int findDuplicate(vector<int> &nums) {
    int slow = 0, fast = 0;

    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];

        if (slow == fast) break;
    }
    int second = 0;
    while (true) {
        slow = nums[slow];
        second = nums[second];

        if (slow == second) {
            return slow;
        }
    }

    return -1;
}