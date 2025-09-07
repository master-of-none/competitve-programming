#include "header.h"
using namespace std;

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) return res;

    unordered_map<char, string> hashmap = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    function<void(int, string)> dfs = [&](int i, string curStr) {
        if (curStr.size() == digits.size()) {
            res.push_back(curStr);
            return;
        }

        for (char c : hashmap[digits[i]]) {
            dfs(i + 1, curStr + c);
        }
    };
    dfs(0, "");
    return res;
}
