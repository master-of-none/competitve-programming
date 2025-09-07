#include "header.h"
using namespace std;
bool overlap(vector<int>& a, vector<int>& b);

vector<vector<int>> insert(vector<vector<int>>& intervals,
                           vector<int>& newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;

    for (auto interval : intervals) {
        if (res.empty() or not(overlap(res.back(), interval))) {
            res.push_back(interval);
        } else {
            res.back()[1] = max(res.back()[1], interval[1]);
        }
    }

    return res;
}
bool overlap(vector<int>& a, vector<int>& b) {
    return (not((b[1] < a[0]) or (a[1] < b[0])));
}
