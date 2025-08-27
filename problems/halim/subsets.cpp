#include "header.h"
using namespace std;

vector<vector<int>> subsets(int n) {
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }
    vector<int> path;
    vector<vector<int>> res;

    function<void(int)> dfs = [&](int i) {
        if (i >= (int)nums.size()) {
            res.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        dfs(i + 1);
        path.pop_back();
        dfs(i + 1);
    };
    dfs(0);
    return res;
}

int main() {
    int n = 20;
    vector<vector<int>> res = subsets(n);
    ofstream fout("subsets.txt");
    for (auto &p : res) {
        for (int x : p) {
            fout << x << " ";
        }
        fout << "\n";
    }
    fout.close();
    return 0;
}