#include "header.h"
using namespace std;

vector<string> permutations(const string &s) {
    vector<string> res;
    string path;
    vector<bool> used(s.size(), false);

    function<void(int)> dfs = [&](int start) {
        if (start == (int)s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < (int)s.size(); i++) {
            if (used[i]) continue;

            path.push_back(s[i]);
            used[i] = true;
            dfs(start + 1);

            path.pop_back();
            used[i] = false;
        }
    };
    dfs(0);
    return res;
}

int main() {
    string s = "ABCDEFGHIJ";
    vector<string> res = permutations(s);

    ofstream fout("permutations.txt");
    for (auto &p : res) {
        fout << p << "\n";
    }
    fout.close();
    return 0;
}