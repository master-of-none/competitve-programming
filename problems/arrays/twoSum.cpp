#include <gtest/gtest.h>

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hashmap;

        for (size_t i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (hashmap.find(diff) != hashmap.end()) {
                return {hashmap[diff], static_cast<int>(i)};
            }
            hashmap[nums[i]] = i;
        }
        return {};
    }
};

TEST(TwoSumTest, BasicCase) {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    EXPECT_EQ(result.size(), 2);
    EXPECT_TRUE((result[0] == 0 && result[1] == 1) ||
                (result[0] == 1 && result[1] == 0));
}

TEST(TwoSumTest, NegativeNumbers) {
    Solution sol;
    vector<int> nums = {-3, 4, 3, 90};
    int target = 0;
    vector<int> result = sol.twoSum(nums, target);
    EXPECT_TRUE((result[0] == 0 && result[1] == 2) ||
                (result[0] == 2 && result[1] == 0));
}

TEST(TwoSumTest, NoSolution) {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int target = 7;
    vector<int> result = sol.twoSum(nums, target);
    EXPECT_TRUE(result.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}