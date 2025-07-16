#include <gtest/gtest.h>

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> productOfArray(vector<int> &nums) {
        vector<int> res(nums.size(), 1);
        int prefix = 1;

        for (size_t i = 0; i < nums.size(); i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};

TEST(ProductOfArrayTest, BasicCase) {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> expected = {24, 12, 8, 6};
    EXPECT_EQ(sol.productOfArray(nums), expected);
}

TEST(ProductOfArrayTest, WithZero) {
    Solution sol;
    vector<int> nums = {0, 1, 2, 3};
    vector<int> expected = {6, 0, 0, 0};
    EXPECT_EQ(sol.productOfArray(nums), expected);
}

TEST(ProductOfArrayTest, AllZerosExceptOne) {
    Solution sol;
    vector<int> nums = {0, 0, 5, 0};
    vector<int> expected = {0, 0, 0, 0};
    EXPECT_EQ(sol.productOfArray(nums), expected);
}

TEST(ProductOfArrayTest, SingleElement) {
    Solution sol;
    vector<int> nums = {10};
    vector<int> expected = {1};
    EXPECT_EQ(sol.productOfArray(nums), expected);
}

TEST(ProductOfArrayTest, EmptyArray) {
    Solution sol;
    vector<int> nums = {};
    vector<int> expected = {};
    EXPECT_EQ(sol.productOfArray(nums), expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}