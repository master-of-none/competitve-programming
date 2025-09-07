#include "header.h"
using namespace std;

vector<int> dailyTemperatures(vector<int> temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        int t = temperatures[i];
        while (!st.empty() and t > st.top().first) {
            auto [stackT, stackInd] = st.top();
            st.pop();
            res[stackInd] = i - stackInd;
        }
        st.push({t, i});
    }
    return res;
}