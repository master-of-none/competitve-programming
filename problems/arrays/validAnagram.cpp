#include <gtest/gtest.h>

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        if (s.size() != t.size()) {
            return false;
        }

        for (size_t i = 0; i < s.size(); i++) {
            bool foundS, foundT;
            foundS = countS.find(s[i]) != countS.end();
            foundT = countT.find(t[i]) != countT.end();

            if (foundS) {
                countS[s[i]] += 1;
            } else {
                countS[s[i]] = 1;
            }

            if (foundT) {
                countT[t[i]] += 1;
            } else {
                countT[t[i]] = 1;
            }
        }
        return countS == countT;
    }
};

TEST(ValidAnagramTest, Valid) {
    Solution sol;
    string s = "racecar";
    string t = "carrace";

    EXPECT_TRUE(sol.isAnagram(s, t));
}

TEST(ValidAnagramTest, Invalid) {
    Solution sol;
    string s = "bat";
    string t = "cat";

    EXPECT_FALSE(sol.isAnagram(s, t));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}