#include "header.h"
using namespace std;

vector<vector<int>> closestPoint(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        heap;

    for (auto& p : points) {
        int x = p[0], y = p[1];
        int dist = x * x + y * y;
        heap.push({dist, {x, y}});
    }

    vector<vector<int>> res;

    while (k-- > 0 and !heap.empty()) {
        auto top = heap.top();
        heap.pop();
        res.push_back({top.second.first, top.second.second});
    }
    return res;
}