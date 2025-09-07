#include "header.h"
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> hashset;

    int l = 0;
    int res = 0;
    for (int r = 0; r < s.size(); r++) {
        while (hashset.find(s[r]) != hashset.end()) {
            hashset.erase(s[l]);
            l++;
        }
        hashset.insert(s[r]);
        res = max(r - l + 1, res);
    }
    return res;
}
