#include <gtest/gtest.h>

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsduplicate(vector<int> &nums) {
        unordered_set<int> hashset;

        for (int n : nums) {
            if (hashset.find(n) != hashset.end()) {
                return true;
            }
            hashset.insert(n);
        }

        return false;
    };
};

TEST(ContainsDuplicateTest, NoDuplicates) {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_FALSE(sol.containsduplicate(nums));
}

TEST(ContainsDuplicateTest, HasDuplicates) {
    Solution sol;
    vector<int> nums = {1, 2, 3, 2};
    EXPECT_TRUE(sol.containsduplicate(nums));
}

TEST(ContainsDuplicateTest, EmptyVector) {
    Solution sol;
    vector<int> nums = {};
    EXPECT_FALSE(sol.containsduplicate(nums));
}

TEST(ContainsDuplicateTest, SingleElement) {
    Solution sol;
    vector<int> nums = {42};
    EXPECT_FALSE(sol.containsduplicate(nums));
}

TEST(ContainsDuplicateTest, AllSame) {
    Solution sol;
    vector<int> nums = {7, 7, 7, 7};
    EXPECT_TRUE(sol.containsduplicate(nums));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}