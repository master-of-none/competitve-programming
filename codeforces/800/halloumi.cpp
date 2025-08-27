#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool check_sort(const vector<int> &a) { return is_sorted(a.begin(), a.end()); }

int main() {
    int testcase;
    cin >> testcase;

    while (testcase--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (k == 1) {
            if (check_sort(a)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "YES\n";
        }
    }
}