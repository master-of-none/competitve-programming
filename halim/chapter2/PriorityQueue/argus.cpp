/* @JUDGE_ID: 1709779 01203 C++ "Argus" */

//!
//! Solved By: Shrikrishna Bhat
//!

#include <functional>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        pq;
    std::map<int, int> period;

    std::string s;
    int qnum, p;

    while (std::cin >> s && s != "#") {
        std::cin >> qnum >> p;
        pq.emplace(p, qnum);
        period[qnum] = p;
    }
    int k;
    std::cin >> k;
    while (k--) {
        auto [time, q] = pq.top();
        pq.pop();
        std::cout << q << "\n";

        pq.emplace(time + period[q], q);
    }
    return 0;
}

// Works with C++23 not C++ 11 which is default compiler in UVa